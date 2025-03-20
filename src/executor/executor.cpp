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

void tensor_dump(Tensor* x, size_t max_show_dims, size_t max_show_elems, std::string msg) {
    std::ofstream outFile("tensor_dump_all_out.txt", std::ios::app);
    if (!outFile.is_open()) {
        return;
    }

    outFile << "-----------------------------Dumping tensor------------------------------------\n";
    outFile << "TENSOR Type: " << (size_t)x->m_dtype << "\n";
    outFile << "Dims: " << x->m_shape[1] << " * " << x->m_shape[0] << "\n";
    outFile << "Notes: " << msg << "\n";
    outFile << "Dumping data:\n";

    for (size_t i = 0; i < max_show_dims && i < x->m_shape[1]; i++) {
        outFile << "Dimension " << i << ":";
        for (size_t j = 0; j < max_show_elems && j < x->m_shape[0]; j++) {
            float value = *((float *)x->get<CPUBuffer>().m_data + i * x->m_shape[0] + j);
            outFile << " " << std::fixed << std::setprecision(6) << value;
        }
        outFile << "\n";
    }
    outFile << "-----------------------------Tensor dump finished!-----------------------------\n";
}

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
    POWERSERVE_LOG_INFO("\033[32m  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$Enter Executor::run()...$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\033[0m");
    auto &model_id = m_graph.m_model_id;
    plan();

    for (auto op : m_graph.ops) {
        switch (op->op) {
        case OpType::GET_EMBEDDING: {
            POWERSERVE_LOG_DEBUG("\033[36m ((((((((((((calling CPU OpType::GET_EMBEDDING)))))))))))) \033[0m");
            auto weight   = op->prev[0]->tensor();
            auto out      = op->output();
            auto [tokens] = op->get_params<GetEmbeddingParams>();
            m_platform.ggml_backends[model_id]->get_embedding(out, weight, tokens);

            tensor_dump(out, 4, 128, "Embedding OUT Tensor");
        } break;

        case OpType::ADD: {
            auto a   = op->prev[0]->tensor();
            auto b   = op->prev[1]->tensor();
            auto out = op->output();
            m_platform.ggml_backends[model_id]->add(out, a, b);
        } break;

        case OpType::MAT_MUL: {
            POWERSERVE_LOG_DEBUG("\033[36m ((((((((((((calling CPU OpType::MAT_MUL)))))))))))) \033[0m");
            auto a   = op->prev[0]->tensor();
            auto b   = op->prev[1]->tensor();
            auto out = op->output();
            m_platform.ggml_backends[model_id]->matmul(out, a, b);
        } break;

        case OpType::RMS_NORM: {
            POWERSERVE_LOG_DEBUG("\033[36m ((((((((((((calling CPU OpType::RMS_NORM)))))))))))) \033[0m");
            auto x      = op->prev[0]->tensor();
            auto weight = op->prev[1]->tensor();
            auto out    = op->output();
            auto [eps]  = op->get_params<RMSNormParams>();
            m_platform.ggml_backends[model_id]->rmsnorm(out, x, weight, eps);
        } break;

        case OpType::SILU_HADAMARD: {
            auto gate = op->prev[0]->tensor();
            auto up   = op->prev[1]->tensor();
            auto out  = op->output();
            m_platform.ggml_backends[model_id]->silu_hadamard(out, gate, up);
        } break;

        case OpType::ROPE: {
            POWERSERVE_LOG_DEBUG("\033[36m ((((((((((((calling CPU OpType::ROPE)))))))))))) \033[0m");
            auto src             = op->prev[0]->tensor();
            auto out             = op->next[0]->tensor();
            auto [pos, rope_cfg] = op->get_params<RopeParams>();
            m_platform.ggml_backends[model_id]->rope(out, src, pos, rope_cfg);

            tensor_dump(out, 4, 128, "Rope OUT Tensor");
        } break;

        case OpType::SOFTMAX: {
            auto x   = op->prev[0]->tensor();
            auto out = op->output();
            m_platform.ggml_backends[model_id]->softmax(out, x);
        } break;

        case OpType::COPY: {
            auto dst = op->prev[0]->tensor();
            auto src = op->prev[1]->tensor();
            m_platform.ggml_backends[model_id]->copy(dst, src);
        } break;

#if defined(POWERSERVE_WITH_QNN)
        case OpType::QNN_FORWARD: {
            POWERSERVE_LOG_DEBUG("\033[36m #########((((((((((((<<<<<<<<<<<<<<<calling QNN OpType::QNN_FORWARD start>>>>>>>>>>>>>>>))))))))))))######### \033[0m");
            auto x     = op->prev[0]->tensor();
            auto out   = op->output();
            auto pos   = op->get_params<QNNForwardParams>().pos;
            auto &mask = op->get_params<QNNForwardParams>().mask;
            m_platform.qnn_backend->forward(m_graph.m_model_id, out, x, pos, mask);

            tensor_dump(out, 4, 128, "QNN OUT Tensor");

            POWERSERVE_LOG_DEBUG("\033[36m #########((((((((((((<<<<<<<<<<<<<<<calling QNN OpType::QNN_FORWARD end>>>>>>>>>>>>>>>))))))))))))########## \033[0m");
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
            auto x    = op->prev[0]->tensor();
            auto size = op->get_params<PrintParams>().size;
            m_platform.ggml_backends[model_id]->print(x, size);

        } break;

        case OpType::ADD_CACHE: {
            auto k                 = op->prev[0]->tensor();
            auto v                 = op->prev[1]->tensor();
            auto [L, pos, head_id] = op->get_params<AddCacheParams>();
            m_platform.ggml_backends[model_id]->add_cache(k, v, L, pos, head_id);
        } break;

        case OpType::PERMUTE: {
            auto x      = op->prev[0]->tensor();
            auto out    = op->output();
            auto [axes] = op->get_params<PermuteParams>();
            m_platform.ggml_backends[model_id]->permute(out, x, axes);
        } break;

        case OpType::CONT: {
            auto x   = op->prev[0]->tensor();
            auto out = op->output();
            m_platform.ggml_backends[model_id]->cont(out, x);
        } break;

        case OpType::VIEW: {
            auto out                       = op->output();
            auto [stride, offset]          = op->get_params<ViewParams>();
            out->get<CPUBuffer>().m_stride = stride;
            out->get<CPUBuffer>().m_data   = (char *)out->get<CPUBuffer>().m_data + offset;
        } break;

        case OpType::SOFTMAX_EXT: {
            auto out               = op->output();
            auto x                 = op->prev[0]->tensor();
            auto mask              = op->prev[1]->tensor();
            auto [scale, max_bias] = op->get_params<SoftmaxExtParams>();

            m_platform.ggml_backends[model_id]->softmax_ext(out, x, mask, scale, max_bias);
        } break;

        case OpType::GET_MASK: {
            auto out         = op->output();
            auto [mask, pos] = op->get_params<GetMaskParams>();
            auto n_kv        = out->m_shape[0];
            auto batch_size  = out->m_shape[1];

            POWERSERVE_ASSERT(out->m_dtype == DataType::FP32);
            auto mask_buf = (float *)out->get<CPUBuffer>().m_data;
            for (size_t i = 0; i < batch_size; i++) {
                size_t cur_pos = pos[i];
                for (size_t j = 0; j < n_kv; j++) {
                    mask_buf[j + i * n_kv] = (j <= cur_pos) ? 0.f : -INFINITY;
                }
            }
        } break;

        case OpType::TRANSPOSE: {
            auto x   = op->prev[0]->tensor();
            auto out = op->output();
            m_platform.ggml_backends[model_id]->transpose(out, x);
        } break;
        default:
            POWERSERVE_ABORT("Unknown OpType: {}", static_cast<int>(op->op));
        }
    }

    POWERSERVE_LOG_INFO("\033[32m$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$Exit Executor::run()...$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\033[0m");
}
} // namespace powerserve
