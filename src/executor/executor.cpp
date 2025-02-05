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

#include "executor/executor.hpp"

#include "core/logger.hpp"

#include <cstdint>

namespace powerserve {

void Executor::allocate_buffers() {
    for (auto tensor : m_graph.tensors) {
        if (tensor->m_data) {
            continue;
        }

        switch (tensor->m_dtype) {
        case DataType::FP32: {
            create_cpu_buffer<float>(tensor);
        } break;

        case DataType::INT32: {
            create_cpu_buffer<int32_t>(tensor);
        } break;
        case DataType::INT64: {
            create_cpu_buffer<int64_t>(tensor);
        } break;

        default:
            POWERSERVE_ABORT("could not allocate buffer for data type: {}", static_cast<int>(tensor->m_dtype));
        }
    }
}

void Executor::plan() {
    m_platform.ggml_backends[m_graph.m_model_id]->plan(m_graph.ops);
}

void Executor::run() {
    auto &model_id = m_graph.m_model_id;
    plan();

    // fmt::println("no bug inside executor 1......");

    for (auto op : m_graph.ops) {
        switch (op->op) {
        case OpType::GET_EMBEDDING: {
            // fmt::println("no bug inside executor embed 0......");
            auto weight   = op->prev[0]->tensor();
            auto out      = op->output();
            auto [tokens] = op->get_params<GetEmbeddingParams>();
            // fmt::println("no bug inside executor embed 1......");
            m_platform.ggml_backends[model_id]->get_embedding(out, weight, tokens);
            // fmt::println("no bug inside executor embed 2......");
        } break;

        case OpType::ADD: {
            // fmt::println("no bug inside executor add 0......");
            auto a   = op->prev[0]->tensor();
            auto b   = op->prev[1]->tensor();
            auto out = op->output();
            // fmt::println("no bug inside executor add 1......");
            m_platform.ggml_backends[model_id]->add(out, a, b);
            // fmt::println("no bug inside executor add 2......");
        } break;

        case OpType::MAT_MUL: {
            // fmt::println("no bug inside executor matmul 0......");
            auto a   = op->prev[0]->tensor();
            auto b   = op->prev[1]->tensor();
            auto out = op->output();
            // fmt::println("no bug inside executor matmul 1......");
            m_platform.ggml_backends[model_id]->matmul(out, a, b);
            // fmt::println("no bug inside executor matmul 2......");
        } break;

        case OpType::RMS_NORM: {
            // fmt::println("no bug inside executor rmsnorm 0......");
            auto x      = op->prev[0]->tensor();
            auto weight = op->prev[1]->tensor();
            auto out    = op->output();
            auto [eps]  = op->get_params<RMSNormParams>();
            // fmt::println("no bug inside executor rmsnorm 1......");
            m_platform.ggml_backends[model_id]->rmsnorm(out, x, weight, eps);
            // fmt::println("no bug inside executor rmsnorm 2......");
        } break;

        case OpType::SILU_HADAMARD: {
            // fmt::println("no bug inside executor silu 0......");
            auto gate = op->prev[0]->tensor();
            auto up   = op->prev[1]->tensor();
            auto out  = op->output();
            // fmt::println("no bug inside executor silu 1......");
            m_platform.ggml_backends[model_id]->silu_hadamard(out, gate, up);
            // fmt::println("no bug inside executor silu 2......");
        } break;

        case OpType::ROPE: {
            // fmt::println("no bug inside executor rope 0......");
            auto src             = op->prev[0]->tensor();
            auto out             = op->next[0]->tensor();
            auto [pos, rope_cfg] = op->get_params<RopeParams>();
            // fmt::println("no bug inside executor rope 1......");
            m_platform.ggml_backends[model_id]->rope(out, src, pos, rope_cfg);
            // fmt::println("no bug inside executor rope 2......");
        } break;

        case OpType::SOFTMAX: {
            // fmt::println("no bug inside executor softmax 0......");
            auto x   = op->prev[0]->tensor();
            auto out = op->output();
            // fmt::println("no bug inside executor softmax 1......");
            m_platform.ggml_backends[model_id]->softmax(out, x);
            // fmt::println("no bug inside executor softmax 2......");
        } break;

        case OpType::COPY: {
            // fmt::println("no bug inside executor copy 0......");
            auto dst = op->prev[0]->tensor();
            auto src = op->prev[1]->tensor();
            // fmt::println("no bug inside executor copy 1......");
            m_platform.ggml_backends[model_id]->copy(dst, src);
            // fmt::println("no bug inside executor copy 2......");
        } break;

#if defined(POWERSERVE_WITH_QNN)
        case OpType::QNN_FORWARD: {
            auto x     = op->prev[0]->tensor();fmt::println("no bug inside executor add 1......");
            auto out   = op->output();
            auto pos   = op->get_params<QNNForwardParams>().pos;
            auto &mask = op->get_params<QNNForwardParams>().mask;
            m_platform.qnn_backend->forward(m_graph.m_model_id, out, x, pos, mask);
        } break;
        case OpType::QNN_FORWARD_VL: {
            auto x                  = op->prev[0]->tensor();
            auto out                = op->output();
            auto pos                = op->get_params<QNNForwardVLParams>().pos;
            auto &mask              = op->get_params<QNNForwardVLParams>().mask;
            auto &pixel_values_list = op->get_params<QNNForwardVLParams>().pixel_values_list;
            auto &img_infos         = op->get_params<QNNForwardVLParams>().img_infos;
            m_platform.qnn_backend->forward(m_graph.m_model_id, out, x, pixel_values_list, img_infos, pos, mask);
            pixel_values_list.clear();
            img_infos.clear();
        } break;
#endif

        case OpType::PRINT: {
            // fmt::println("no bug inside executor print 0......");
            auto x    = op->prev[0]->tensor();
            auto size = op->get_params<PrintParams>().size;
            // fmt::println("no bug inside executor print 1......");
            m_platform.ggml_backends[model_id]->print(x, size);
            // fmt::println("no bug inside executor print 2......");

        } break;

        case OpType::ADD_CACHE: {
            // fmt::println("no bug inside executor add cache 0......");
            auto k                 = op->prev[0]->tensor();
            auto v                 = op->prev[1]->tensor();
            auto [L, pos, head_id] = op->get_params<AddCacheParams>();
            // fmt::println("no bug inside executor add cache 1......");
            m_platform.ggml_backends[model_id]->add_cache(k, v, L, pos, head_id);
            // fmt::println("no bug inside executor add cache 2......");
        } break;

        case OpType::PERMUTE: {
            // fmt::println("no bug inside executor permute 0......");
            auto x      = op->prev[0]->tensor();
            auto out    = op->output();
            auto [axes] = op->get_params<PermuteParams>();
            // fmt::println("no bug inside executor permute 1......");
            m_platform.ggml_backends[model_id]->permute(out, x, axes);
            // fmt::println("no bug inside executor permute 2......");
        } break;

        case OpType::CONT: {
            // fmt::println("no bug inside executor cont 0......");
            auto x   = op->prev[0]->tensor();
            auto out = op->output();
            // fmt::println("no bug inside executor cont 1......");
            m_platform.ggml_backends[model_id]->cont(out, x);
            // fmt::println("no bug inside executor cont 2......");
        } break;

        case OpType::VIEW: {
            // fmt::println("no bug inside executor view 0......");
            auto out                       = op->output();
            auto [stride, offset]          = op->get_params<ViewParams>();
            out->get<CPUBuffer>().m_stride = stride;
            out->get<CPUBuffer>().m_data   = (char *)out->get<CPUBuffer>().m_data + offset;
            // fmt::println("no bug inside executor view 1......");
        } break;

        case OpType::SOFTMAX_EXT: {
            // fmt::println("no bug inside executor softmax ext 0......");
            auto out               = op->output();
            auto x                 = op->prev[0]->tensor();
            auto mask              = op->prev[1]->tensor();
            auto [scale, max_bias] = op->get_params<SoftmaxExtParams>();
            // fmt::println("no bug inside executor softmax ext 1......");

            m_platform.ggml_backends[model_id]->softmax_ext(out, x, mask, scale, max_bias);
            // fmt::println("no bug inside executor softmax ext 2......");
        } break;

        case OpType::GET_MASK: {
            // fmt::println("no bug inside executor get mask 0......");
            auto out         = op->output();
            auto [mask, pos] = op->get_params<GetMaskParams>();
            auto n_kv        = out->m_shape[0];
            auto batch_size  = out->m_shape[1];
            // fmt::println("no bug inside executor get mask 1......");

            POWERSERVE_ASSERT(out->m_dtype == DataType::FP32);
            // fmt::println("no bug inside executor get mask 2......");
            auto mask_buf = (float *)out->get<CPUBuffer>().m_data;
            for (size_t i = 0; i < batch_size; i++) {
                size_t cur_pos = pos[i];
                for (size_t j = 0; j < n_kv; j++) {
                    mask_buf[j + i * n_kv] = (j <= cur_pos) ? 0.f : -INFINITY;
                }
            }
            // fmt::println("no bug inside executor get mask 3......");
        } break;

        case OpType::TRANSPOSE: {
            // fmt::println("no bug inside executor transpose 0......");
            auto x   = op->prev[0]->tensor();
            auto out = op->output();
            // fmt::println("no bug inside executor transpose 1......");
            m_platform.ggml_backends[model_id]->transpose(out, x);
            // fmt::println("no bug inside executor transpose 2......");
        } break;
        default:
            POWERSERVE_ABORT("Unknown OpType: {}", static_cast<int>(op->op));
        }
    }
}
} // namespace powerserve
