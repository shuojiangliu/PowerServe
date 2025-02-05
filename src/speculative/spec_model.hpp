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

#include "model/model.hpp"
#include "speculative/token_tree.hpp"
#include "tokenizer/tokenizer.hpp"

namespace powerserve {

struct SpecTokenIterator : TokenIterator {
public:
    const ModelPtr target_model;
    const ModelPtr draft_model;
    SpeculativeConfig &config;

public:
    SpecTokenIterator(
        TokenTree &token_tree,
        const ModelPtr &target_model,
        const ModelPtr &draft_model,
        const Tokenizer &tokenizer,
        Sampler &sampler,
        SpeculativeConfig &config,
        const std::string &prompt,
        size_t steps,
        size_t batch_size
    ) :
        TokenIterator(steps, prompt, batch_size, tokenizer, sampler),
        target_model(target_model),
        draft_model(draft_model),
        config(config),
        token_tree(token_tree) {
        if (steps <= 0) {
            return;
        }
        POWERSERVE_UNUSED(batch_size);
        fmt::println("no bug inside 1......");
        auto prompt_tokens           = tokenizer.tokenize(prompt, tokenizer.m_vocab.tokenizer_add_bos);
        const size_t n_prompt_tokens = prompt_tokens.size();
        POWERSERVE_ASSERT(n_prompt_tokens >= 1);
        fmt::println("no bug inside 2......");

        target_model->m_platform->reset_kv_position(target_model->m_config->model_id);
        fmt::println("target model id: {}", target_model->m_config->model_id);
        fmt::println("no bug inside 2.3......");
        draft_model->m_platform->reset_kv_position(draft_model->m_config->model_id);
        fmt::println("draft model id: {}", draft_model->m_config->model_id);
        fmt::println("no bug inside 2.4......");
        POWERSERVE_ASSERT(target_model->kv_cache->position == draft_model->kv_cache->position);
        fmt::println("no bug inside 2.5......");
        size_t position = target_model->kv_cache->position;
        fmt::println("no bug inside 3......");

        // spec test: ================================================
        // target_model->m_platform->ggml_backends[target_model->m_config->model_id]->setup_threadpool();
        // draft_model->m_platform->ggml_backends[draft_model->m_config->model_id]->setup_threadpool();
        // ===========================================================

        const size_t n_prefill_tokens = n_prompt_tokens - 1;

        std::vector<Token> prefill_tokens(prompt_tokens.begin(), prompt_tokens.begin() + n_prefill_tokens);

        std::vector<int> prefill_positions(n_prefill_tokens);
        std::iota(prefill_positions.begin(), prefill_positions.end(), position);
        fmt::println("no bug inside 4......");

        CausalAttentionMask prefill_attention_mask(n_prefill_tokens);
        target_model->forward(prefill_tokens, prefill_positions, prefill_attention_mask, false);
        fmt::println("no bug inside 5......");
        draft_model->forward(prefill_tokens, prefill_positions, prefill_attention_mask, false);
        fmt::println("no bug inside 6......");

        position = target_model->kv_cache->position;
        m_tokens.push_back(prompt_tokens.back());
    }

    ~SpecTokenIterator() = default;

    virtual void decode() override {
        // TODO: decode
        if (n_rest > 0 && m_tokens.size() >= 1) {
            fmt::print("\033[35m (Inside SpecTokenIterator::decode()) m_tokens.size() == {}\033[0m\n", m_tokens.size());

            if (m_tokens.size() == 1) {
                auto last_token = m_tokens.back();
                fmt::println("\033[35m (Inside SpecTokenIterator::decode()) reach m_tokens.size() == 1, go to generation logics; the last token is: {} (#{})\033[0m", m_tokenizer.to_string(last_token), last_token);

                generate_tokens(m_tokenizer, m_sampler, last_token);
                POWERSERVE_ASSERT(token_queue.size() > 0);

                fmt::print("\033[35m     (Inside SpecTokenIterator::decode()) token queue: \033[0m");
                for (auto token : token_queue) {
                    m_tokens.push_back(token);
                    fmt::print("\033[35m {} (#{}), \033[0m", m_tokenizer.to_string(token), token);
                }
                token_queue.clear();
                fmt::println("");
            } else {
                fmt::print("\033[35m     (Inside SpecTokenIterator::decode()) Skip forward for this iteration!\033[0m");
            }

            --n_rest;
            m_tokens.pop_front();
        }
    }

private:
    TokenTree &token_tree;
    std::deque<Token> token_queue;

    void generate_tokens(const Tokenizer &tokenizer, Sampler &sampler, Token last_token) {
        token_tree.draft(draft_model, tokenizer, config.draft_batch_size, last_token);

        CausalAttentionMask mask(config.draft_batch_size, token_tree.attention_mask());

        fmt::println("\033[31m      (Inside TokenTree::generate_tokens()) Start forwarding in target model (slow!)\033[0m");
        auto ret = target_model->forward(token_tree.tokens(), token_tree.positions(), mask);

        target_model->kv_cache->rollback_tokens(config.draft_batch_size);

        token_tree.verify(target_model, draft_model, sampler, ret.logits_vector, [this](Token token) {
            token_queue.push_back(token);
        });

        if (config.token_tree.debug) {
            fmt::print("\033[31m\n========================================DEBUG TOKEN TREE START=========================================\n\033[0m");
            token_tree.print_tree(tokenizer);
            fmt::print("\033[31m\n========================================DEBUG TOKEN TREE END===========================================\n\033[0m");
        }
    }
};

struct SpeculativeModel {

public:
    const ModelPtr target_model;
    const ModelPtr draft_model;
    SpeculativeConfig config;

    SpeculativeModel(const ModelPtr &target_model, const ModelPtr &draft_model, const SpeculativeConfig &config) :
        target_model(target_model),
        draft_model(draft_model),
        config(config),
        token_tree(config) {}

    ~SpeculativeModel() = default;

public:
    auto generate(const Tokenizer &tokenizer, Sampler &sampler, const std::string &prompt, int steps, size_t batch_size)
        -> std::shared_ptr<TokenIterator> {
        return std::make_shared<SpecTokenIterator>(
            token_tree, target_model, draft_model, tokenizer, sampler, config, prompt, steps, batch_size
        );
    }

    void print_stat() {
        token_tree.print_stat();
    }

private:
    TokenTree token_tree;
};

} // namespace powerserve
