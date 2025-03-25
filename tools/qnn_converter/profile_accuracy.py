import os
import json
import subprocess
import argparse
from pathlib import Path

parser = argparse.ArgumentParser()
parser.add_argument('--build-folder', type=str, default="./build")
parser.add_argument("--profile-folder", type=str, default="./profile")
parser.add_argument("--chunk-idx", type=int, required=True)
parser.add_argument("--batch-size", type=int, required=True)
parser.add_argument("--batch-idx", type=int, required=True)
parser.add_argument("--silent", action="store_true", help="Hide the shell command arguments.")
args = parser.parse_args()

build_folder_path=Path(args.build_folder)
profile_folder_path=Path(args.profile_folder)

qnn_sdk_folder = os.getenv("QNN_SDK_ROOT")
assert qnn_sdk_folder is not None, "QNN_SDK_ROOT is not set"
ACCURACY_DEBUGGER_PATH = Path(qnn_sdk_folder)/'bin'/'x86_64-linux-clang'/'qnn-accuracy-debugger'

def run(cmd_args: list):
    cmd = ' '.join(map(str, cmd_args))
    if args.silent:
        cmd_short = " ".join(map(str, cmd_args[:2]))
        print(f"> {cmd_short}")
    else:
        print(f'> {cmd}')
    ret = subprocess.Popen(cmd, shell=True).wait()
    assert ret == 0


def generate_reference_data():
    cmd = [
        ACCURACY_DEBUGGER_PATH,
        '--framework_runner',
        '-f', 'onnx',
        '-m', str(build_folder_path/f'model_chunk_{args.chunk_idx}'/f'batch_{args.batch_size}'/'onnx_model'/f'batch_{args.batch_size}.onnx'),
        '--output_dirname', f'model_chunk_{args.chunk_idx}/batch_{args.batch_size}/idx_{args.batch_idx}',
        '--disable_graph_optimization',
        '-w', f'{args.profile_folder}'
    ]

    if not args.silent:
        cmd += ['-v']

    with open(build_folder_path/f'model_chunk_{args.chunk_idx}'/f'batch_{args.batch_size}'/f'batch_{args.batch_size}.io.json', "r") as f:
        tensors = json.load(f)

    for tensor in tensors:
        if tensor['type'] == 'in':
            cmd += [
                '-i',
                '"' + tensor['name'] + '"',
                str(tensor['shape'][0]) + ',' + str(tensor['shape'][1]),
                str(build_folder_path/f'model_chunk_{args.chunk_idx}'/f'batch_{args.batch_size}'/'data'/f'{args.batch_idx}'/f"{tensor['name']}.raw")
            ]
        else:
            cmd += [
                '-o',
                '"' + tensor['name'] + '"',
                str(tensor['shape'][0]) + ',' + str(tensor['shape'][1]),
                str(build_folder_path/f'model_chunk_{args.chunk_idx}'/f'batch_{args.batch_size}'/'data'/f'{args.batch_idx}'/f"{tensor['name']}.raw")
            ]
    run(cmd)


def generate_qnn_data():
    # FIXME: QNN data generation reports error with graph finalization
    qnn_data_path = profile_folder_path/'inference_engine'/f'model_chunk_{args.chunk_idx}'/f'batch_{args.batch_size}'/f'idx_{args.batch_idx}'
    qnn_data_path.mkdir(parents=True, exist_ok=True)

    with open(str(qnn_data_path/'input_list_slice.txt'), 'w+') as f_out:
        with open(str(build_folder_path/f'model_chunk_{args.chunk_idx}'/f'batch_{args.batch_size}'/'input_list.txt'), 'r') as f_in:
            lines = f_in.readlines()
            if 0 <= args.batch_idx < len(lines):
                f_out.write(lines[args.batch_idx])

    cmd = [
        ACCURACY_DEBUGGER_PATH,
        '--inference_engine',
        '--stage', 'compiled',
        '--runtime', 'htp', '--use_native_input_files',
        '--architecture', 'x86_64-linux-clang',
        '--output_dirname', f'model_chunk_{args.chunk_idx}/batch_{args.batch_size}/idx_{args.batch_idx}',
        '-qmb', str(build_folder_path/f'model_chunk_{args.chunk_idx}'/'x86_64-linux-clang'/f'libbatch_{args.batch_size}.so'),
        '--engine_path', os.getenv('QNN_SDK_ROOT'),
        '--input_list', str(qnn_data_path/'input_list_slice.txt'),
        '--golden_dir_for_mapping', str(profile_folder_path/'framework_runner'/f'model_chunk_{args.chunk_idx}'/f'batch_{args.batch_size}'/f'idx_{args.batch_idx}'),
        '-w', f'{args.profile_folder}',
        f'{"" if args.silent else "--verbose"}',
    ]
    run(cmd)


def compare_results():
    cmd = [
        ACCURACY_DEBUGGER_PATH,
        '--verification',
        '--default_verifier', 'CosineSimilarity',
        '--output_dirname', f'model_chunk_{args.chunk_idx}/batch_{args.batch_size}/idx_{args.batch_idx}',
        '--golden_output_reference_directory', str(profile_folder_path/'framework_runner'/f'model_chunk_{args.chunk_idx}'/f'batch_{args.batch_size}'/f'idx_{args.batch_idx}'),
        '--inference_results', str(profile_folder_path/'inference_engine'/f'model_chunk_{args.chunk_idx}'/f'batch_{args.batch_size}'/f'idx_{args.batch_idx}'),
        '-w', f'{args.profile_folder}',
    ]
    run(cmd)


generate_reference_data()
generate_qnn_data()
compare_results()