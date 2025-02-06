// Copyright 2024-2025 PowerServe Authors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "cmdline.hpp"
#include "core/logger.hpp"
#include "core/timer.hpp"
#include "model/model_loader.hpp"
#include "model/module/norm_attention.hpp"
#include "sampler/sampler_chain.hpp"
#include "speculative/spec_model.hpp"
#include "tokenizer/tokenizer.hpp"

#include <cstddef>
#include <cstdlib>
#include <memory>
#include <string>

int main(int argc, char *argv[]) {
    const powerserve::CommandLineArgument args = powerserve::parse_command_line("PowerServe CLI", argc, argv);
    const powerserve::Config config            = powerserve::get_config_from_argument(args);

    std::shared_ptr<powerserve::Model> main_model  = powerserve::load_model(config.main_model_dir);
    std::shared_ptr<powerserve::Model> draft_model = nullptr;
    if (args.use_spec) {
        draft_model = powerserve::load_model(config.draft_model_dir);
    }
    POWERSERVE_LOG_INFO("after model init: {}", powerserve::perf_get_mem_result());

    const auto [sampler_config, n_threads, batch_size] = config.hyper_params;
    main_model->m_platform                             = std::make_shared<powerserve::Platform>();
    auto &platform                                     = main_model->m_platform;

    platform->init_ggml_backend(main_model->m_config, config.hyper_params);

    if (args.use_spec) {
        draft_model->m_platform = platform;
        platform->init_ggml_backend(draft_model->m_config, config.hyper_params);
        // speculative decoding cpu: =================================================================
        main_model->kv_cache = platform->ggml_backends[main_model->m_config->model_id]->m_kv->kv_cache.get();
        draft_model->kv_cache = platform->ggml_backends[draft_model->m_config->model_id]->m_kv->kv_cache.get();
        // ===========================================================================================
    }

#if defined(POWERSERVE_WITH_QNN)
    if (!args.no_qnn) {
        auto &qnn_backend = main_model->m_platform->qnn_backend;
        main_model->m_platform->init_qnn_backend(args.qnn_lib_folder);
        qnn_backend->load_model(config.main_model_dir / powerserve::qnn::QNN_WORKSPACE_DIR_NAME, main_model->m_config);
        main_model->kv_cache = platform->qnn_backend->m_models[main_model->m_config->model_id]->kv_cache.get();

        if (args.use_spec) {
            qnn_backend->load_model(
                config.draft_model_dir / powerserve::qnn::QNN_WORKSPACE_DIR_NAME, draft_model->m_config
            );
            draft_model->kv_cache = platform->qnn_backend->m_models[draft_model->m_config->model_id]->kv_cache.get();
        }
    }
#endif
    POWERSERVE_LOG_INFO("after platform init: {}", powerserve::perf_get_mem_result());

    main_model->m_attn = std::make_shared<powerserve::NormAttention>(main_model->m_config->llm, main_model->m_weights);
    if (args.use_spec) {
        draft_model->m_attn =
            std::make_shared<powerserve::NormAttention>(draft_model->m_config->llm, draft_model->m_weights);
    }
    POWERSERVE_LOG_INFO("after attn init: {}", powerserve::perf_get_mem_result());

    const std::string tokenizer_path = config.main_model_dir / powerserve::MODEL_VOCAB_FILENAME;
    powerserve::Tokenizer tokenizer(tokenizer_path);
    POWERSERVE_LOG_INFO("after tokenizer init: {}", powerserve::perf_get_mem_result());

    powerserve::SamplerChain sampler{sampler_config, tokenizer};
    POWERSERVE_LOG_INFO("after sampler init: {}", powerserve::perf_get_mem_result());

    {
        POWERSERVE_LOG_INFO("prompt      : {:?}", powerserve::abbreviation(args.prompt, 50));
        POWERSERVE_LOG_INFO("n_predicts  : {}", args.num_predict);
        POWERSERVE_LOG_INFO("model arch  : {}", main_model->m_config->arch);
        POWERSERVE_LOG_INFO("n_threads   : {}", n_threads);
        POWERSERVE_LOG_INFO("batch_size   : {}", batch_size);
    }

    // generate
    long prefill_start = 0;
    long prefill_end   = 0;
    long decode_end    = 0;
    bool start         = false;
    int actual_predict = 0;
    for (const powerserve::Token prompt_token : tokenizer.tokenize(args.prompt, tokenizer.m_vocab.tokenizer_add_bos)) {
        fmt::print("{}", tokenizer.to_string(prompt_token, false));
    }
    prefill_start = powerserve::timestamp_ms();

    std::shared_ptr<powerserve::TokenIterator> iter = nullptr;
#if defined(POWERSERVE_WITH_QNN)
    std::shared_ptr<powerserve::SpeculativeModel> spec_model = nullptr;
    if (args.use_spec) {
        spec_model = std::make_shared<powerserve::SpeculativeModel>(main_model, draft_model, args.speculative_config);
        iter       = spec_model->generate(tokenizer, sampler, args.prompt, args.num_predict, batch_size);
    } else
#endif
    // speculative decoding cpu: =============================================
    std::shared_ptr<powerserve::SpeculativeModel> spec_model = nullptr;
    // =======================================================================
    {
        // uncomment this for non-spec!!!!
        // iter = main_model->generate(tokenizer, sampler, args.prompt, args.num_predict, batch_size);

        // speculative decoding cpu: =========================================
        spec_model = std::make_shared<powerserve::SpeculativeModel>(main_model, draft_model, args.speculative_config);
        fmt::println("\nNot bug here2......");
        /**
         * Note: There is a bug here: after spec_model->generate(), *one of* the thread pool will be freed,
         * causing the subsequent execution failure (There is further code logic checking whether the thread pool is null).
         * This might be related to the lifetime management of smart pointers in C++ or something else.
         * As a temporary workaround, I have to call setup_threadpool() again after spec_model->generate().
         * Therefore, some better way needs to be figured out to handle the management of thread pools.
         */
        main_model->m_platform->ggml_backends[main_model->m_config->model_id]->setup_threadpool();
        draft_model->m_platform->ggml_backends[draft_model->m_config->model_id]->setup_threadpool();
        iter       = spec_model->generate(tokenizer, sampler, args.prompt, args.num_predict, batch_size);
        fmt::println("Not bug here3......");

        main_model->m_platform->ggml_backends[main_model->m_config->model_id]->setup_threadpool();
        draft_model->m_platform->ggml_backends[draft_model->m_config->model_id]->setup_threadpool();
        // ===================================================================
    }
    prefill_end = powerserve::timestamp_ms();

    fmt::println("Not bug here4......");

    int loopNum = 1;

    std::vector<powerserve::Token> token_printings;

    while (!iter->end()) {
        fmt::println("\033[33m *******************************************************************START OUTER LOOP {}:********************************************************************* \033[0m", loopNum);
        auto next = iter->next();
        if (!start) {
            start = true;
            fmt::println("\033[33m *******************************************************************EARLY END OUTER LOOP {}:************************************************************* \n\n\033[0m", loopNum++);
            continue;
        }
        actual_predict += 1;
        if (next == tokenizer.bos_token()) {
            break;
        }
        if (tokenizer.should_stop(next)) {
            fmt::print("[end of text]");
            break;
        }
        fmt::println("\033[32m\n^^^^^^^^^^^^^^^^^^^^^^^^TEXT: {} (#{})^^^^^^^^^^^^^^^^^^^^^^^^\033[0m", tokenizer.to_string(next, false), next);
        fmt::println("\033[33m *******************************************************************END OUTER LOOP {}:***********************************************************************\n\n\033[0m", loopNum++);
        fflush(stdout);

        token_printings.emplace_back(next);
    }
    fmt::println("");

    fmt::println("\033[32mFinal Output: \033[0m");
    for (auto& tk : token_printings) {
        fmt::print("\033[32m{}\033[0m", tokenizer.to_string(tk, false));
    }
    fmt::println("");

    if (start) {
        decode_end               = powerserve::timestamp_ms();
        const size_t num_prefill = tokenizer.tokenize(args.prompt, tokenizer.m_vocab.tokenizer_add_bos).size() - 1;
        POWERSERVE_LOG_INFO("prefill time: {} s", (double)(prefill_end - prefill_start) / 1000);
        POWERSERVE_LOG_INFO(
            "prefill speed ({} tokens): {} tokens/s",
            num_prefill,
            num_prefill / (double)(prefill_end - prefill_start) * 1000
        );
        POWERSERVE_LOG_INFO(
            "decode speed ({} tokens): {} tokens/s",
            actual_predict,
            actual_predict / (double)(decode_end - prefill_end) * 1000
        );
        POWERSERVE_LOG_INFO(
            "total speed: {} tokens/s", (num_prefill + actual_predict) / (double)(decode_end - prefill_start) * 1000
        );
    }
#if defined(POWERSERVE_WITH_QNN)
    if (args.use_spec) {
        spec_model->print_stat();
    }
#endif

    // speculative decoding cpu: ======================================
    if (args.use_spec) {
        spec_model->print_stat();
    }
    // ================================================================

    return 0;
}
