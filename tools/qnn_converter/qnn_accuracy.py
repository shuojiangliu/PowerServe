"""
Experimental! Need modifications!
"""

import argparse
import os
import json
import subprocess
from pathlib import Path



parser = argparse.ArgumentParser()
parser.add_argument('--model_root_path', type=Path, required=True)
parser.add_argument('--result_path', type=Path, required=True)
parser.add_argument('--job_type', type=str, required=True)
args = parser.parse_args()

model_root_path: Path = args.model_root_path
result_path: Path = args.result_path
job_type: str = args.job_type

ACCURACY_DEBUGGER_PATH = Path(os.getenv('QNN_SDK_ROOT'))/'bin'/'x86_64-linux-clang'/'qnn-accuracy-debugger'
LOG_PATH = result_path/'log.txt'

def run(cmd_args: list):
    cmd = ' '.join(map(str, cmd_args))
    print(f'> {cmd}')
    ret = subprocess.Popen(cmd, shell=True).wait()
    assert ret == 0

if job_type == 'GROUND_TRUTH_GENERATION':
    # Accuracy debugger step 1: generate full-precision intermediate results with onnx
    # Initialize command skeleton
    cmd = [
        ACCURACY_DEBUGGER_PATH,
        '--framework_diagnosis',
        '-f', 'onnx',
        '-m', str(model_root_path/'output_embedding'/'batch_1'/'onnx_model'/'batch_1.onnx'),
        '--output_dirname', result_path,
        '--disable_graph_optimization',
        # '-v',
    ]

    # Get the input / output tensors
    with open(model_root_path/'output_embedding'/'batch_1'/'batch_1.io.json', "r") as f:
        tensors = json.load(f)

    for tensor in tensors:
        if tensor['type'] == 'in':
            cmd += [
                '-i',
                '"' + tensor['name'] + '"',
                str(tensor['shape'][0]) + ',' + str(tensor['shape'][1]),
                str(model_root_path) + '/output_embedding/batch_1/data/0/' + tensor['name'] + '.raw'
            ]
        else:
            cmd += [
                '-o',
                '"' + tensor['name'] + '"',
                str(tensor['shape'][0]) + ',' + str(tensor['shape'][1]),
                str(model_root_path) + '/output_embedding/batch_1/data/0/' + tensor['name'] + '.raw'
            ]
    run(cmd)
elif job_type == 'EMULATION_RESULT_GENERATION':
    # Accuracy debugger step 2: generate device intermediate results with simulated HTP

    # with open(str(model_root_path) + '/output_embedding/batch_1/input_list_validate.txt', 'w+') as f_out:
    #     with open(str(model_root_path) + '/output_embedding/batch_1/input_list.txt', 'r') as f_in:
    #         input_list = f_in.readline().strip()
    #         f_out.write(input_list)

    # Initialize command skeleton
    cmd = [
        ACCURACY_DEBUGGER_PATH,
        '--inference_engine',
        '--stage', 'compiled',
        '-r', 'htp',
        '-a', 'x86_64-linux-clang',
        '--output_dirname', result_path,
        '-qmb', str(model_root_path/'output_embedding'/'x86_64-linux-clang'/'libbatch_1.so'),
        '--engine_path', os.getenv('QNN_SDK_ROOT'),
        '-l', str(model_root_path) + '/output_embedding/batch_1/input_list_validate.txt',
        '--golden_dir_for_mapping', './working_directory/framework_diagnosis',
        '--log_level verbose',
    ]
    run(cmd)
elif job_type == 'EMULATION_RESULT_GENERATION_CPU':
    # Accuracy debugger step 2: generate device intermediate results with simulated HTP

    # with open(str(model_root_path) + '/model_chunk_0/batch_1/input_list_validate.txt', 'w+') as f_out:
    #     with open(str(model_root_path) + '/model_chunk_0/batch_1/input_list.txt', 'r') as f_in:
    #         input_list = f_in.readline().strip()
    #         f_out.write(input_list)

    # Initialize command skeleton
    cmd = [
        ACCURACY_DEBUGGER_PATH,
        '--inference_engine',
        '--stage', 'source',
        '-r', 'cpu',
        '-a', 'x86_64-linux-clang',
        '--output_dirname', result_path,
        '-f', 'onnx',
        '-m', str(model_root_path/'model_chunk_0'/'batch_1'/'onnx_model'/'batch_1.onnx'),
        '--engine_path', os.getenv('QNN_SDK_ROOT'),
        '-l', str(model_root_path) + '/model_chunk_0/batch_1/input_list_validate.txt',
        '--precision int8',
        '-bbw 8', '-abw 8','-wbw 8', '--per_channel_quantization',
        '--log_level verbose',
    ]

    with open(model_root_path/'model_chunk_0'/'batch_1'/'batch_1.io.json', "r") as f:
        tensors = json.load(f)

    for tensor in tensors:
        if tensor['type'] == 'in':
            cmd += [
                '-i',
                '"' + tensor['name'] + '"',
                str(tensor['shape'][0]) + ',' + str(tensor['shape'][1]),
                str(model_root_path) + '/model_chunk_0/batch_1/data/0/' + tensor['name'] + '.raw'
            ]
        else:
            cmd += [
                '-o',
                '"' + tensor['name'] + '"',
                str(tensor['shape'][0]) + ',' + str(tensor['shape'][1]),
                str(model_root_path) + '/model_chunk_0/batch_1/data/0/' + tensor['name'] + '.raw'
            ]
    run(cmd)
elif job_type == 'EMULATION_RESULT_GENERATION_SRC':
    # Accuracy debugger step 2: generate device intermediate results with simulated HTP

    # with open(str(model_root_path) + '/model_chunk_0/batch_1/input_list_validate.txt', 'w+') as f_out:
    #     with open(str(model_root_path) + '/model_chunk_0/batch_1/input_list.txt', 'r') as f_in:
    #         input_list = f_in.readline().strip()
    #         f_out.write(input_list)

    # Initialize command skeleton
    cmd = [
        ACCURACY_DEBUGGER_PATH,
        '--inference_engine',
        '--stage', 'source',
        '-r', 'htp',
        '-a', 'x86_64-linux-clang',
        '--output_dirname', result_path,
        '-f', 'onnx',
        '-m', str(model_root_path/'model_chunk_0'/'batch_1'/'onnx_model'/'batch_1.onnx'),
        '--engine_path', os.getenv('QNN_SDK_ROOT'),
        '-l', str(model_root_path) + '/model_chunk_0/batch_1/input_list_validate.txt',
        '--precision int8',
        '-bbw 8', '-abw 8','-wbw 8', '--per_channel_quantization',
        '--log_level verbose',
    ]

    with open(model_root_path/'model_chunk_0'/'batch_1'/'batch_1.io.json', "r") as f:
        tensors = json.load(f)

    for tensor in tensors:
        if tensor['type'] == 'in':
            cmd += [
                '-i',
                '"' + tensor['name'] + '"',
                str(tensor['shape'][0]) + ',' + str(tensor['shape'][1]),
                str(model_root_path) + '/model_chunk_0/batch_1/data/0/' + tensor['name'] + '.raw'
            ]
        else:
            cmd += [
                '-o',
                '"' + tensor['name'] + '"',
                str(tensor['shape'][0]) + ',' + str(tensor['shape'][1]),
                str(model_root_path) + '/model_chunk_0/batch_1/data/0/' + tensor['name'] + '.raw'
            ]
    run(cmd)
elif job_type == 'COMPARE_RESULTS':
    cmd = [
        ACCURACY_DEBUGGER_PATH,
        '--verification',
        '--default_verifier', 'CosineSimilarity',
        '--golden_output_reference_directory', 'working_directory/framework_diagnosis/trut2h',
        '--inference_results', 'working_directory/inference_engine/inference2/output/Result_0',
    ]
    run(cmd)
