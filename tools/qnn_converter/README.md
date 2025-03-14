# Convert the model in safetensors format to a QNN executable binary format
1. Set up the QNN environment
    - Complete the configuration of the QNN environment following the instructions at https://docs.qualcomm.com/bundle/publicresource/topics/80-63442-50/linux_setup.html?product=1601111740009302.
    - After completing the configuration, navigate to the current directory and set the environment variables as follows:
        ```sh
        export QNN_SDK=/path/to/aforementioned/QNN/installation/directory
        source $QNN_SDK/bin/envsetup.sh
        #If successful, it will display:
        #[INFO] AISW SDK environment set
        #[INFO] QNN_SDK_ROOT: /path/to/aforementioned/QNN/installation/directory
        #[INFO] SNPE_ROOT: /path/to/aforementioned/QNN/installation/directory
        ```
    - You should use the Python virtual environment that was configured when setting up the QNN environment.
        ```sh
        export PYTHON_VENV_PATH=/path/to/python/virtual/environment
        source $PYTHON_VENV_PATH/bin/activate
        
        # Under the directory of qnn converter tools
        pip install -r requirements.txt
        ```
2. Run the one-click conversion script to complete the conversion
    ```sh
    python converter.py \
    --model-folder Llama-3.2-1B-Instruct \
    --model-name llama3_2_1b \
    --system-prompt-file system_prompt_llama.txt \
    --prompt-file lab_intro_llama.md \
    --batch-sizes 1 \
    --artifact-name llama3_2_1b \
    --n-model-chunk 4 \
    --soc sa8295
    # Note:
    # 1. System-prompt-file and lab_intro_llama.md should be adjusted based on whether it is an Instruct model and the model template
    # 2. The number of batch sizes supports up to two.
    # 3. The value of n-model-chunk should ensure that the size of each chunk does not exceed 2G and can evenly divide the number of model layers. For an 8B model, it is recommended to set it to 4.
    ```
    After the conversion is completed, copy the resulting output folder to the correct location  for the QNN model on the phone to run

These commands below are for local debug&record only (Please ignore them):

Smallthinker command:

```sh
python converter.py \
    --model-folder /home/sliu/Projects/New-Attempt/PowerServe/models_hf/smallthinker_3b \
    --model-name smallthinker_3b \
    --system-prompt-file /home/sliu/Projects/New-Attempt/PowerServe/assets/system_prompts/qwen2.txt \
    --prompt-file /home/sliu/Projects/New-Attempt/PowerServe/assets/calibration_data/service_lab_intro_qwen2.txt \
    --batch-sizes 1 \
    --max-n-tokens 200 \
    --artifact-name smallthinker_3b \
    --n-model-chunk 4 \
    --output-folder ./smallthinker_3b_output  \
    --build-folder ./smallthinker_3b_build \
    --soc sa8295
```

Llama3.2-1B command:

```sh
python converter.py \
    --model-folder /home/sliu/Projects/New-Attempt/PowerServe/models_hf/llama3_2_1b \
    --model-name llama3_2_1b \
    --system-prompt-file /home/sliu/Projects/New-Attempt/PowerServe/assets/system_prompts/llama3.txt \
    --prompt-file /home/sliu/Projects/New-Attempt/PowerServe/assets/calibration_data/service_lab_intro_llama3.txt \
    --batch-sizes 1 \
    --max-n-tokens 200 \
    --artifact-name llama3_2_1b \
    --n-model-chunk 4 \
    --output-folder ./llama3_2_1b_output  \
    --build-folder ./llama3_2_1b_build \
    --soc sa8295
```

```shell
python converter.py \
    --model-folder /home/sliu/Projects/New-Attempt/PowerServe/models_hf/llama3_2_1b \
    --model-name llama3_2_1b \
    --system-prompt-file /home/sliu/Projects/New-Attempt/PowerServe/assets/system_prompts/llama3.txt \
    --prompt-file /home/sliu/Projects/New-Attempt/PowerServe/assets/calibration_data/service_lab_intro_llama3.txt \
    --batch-sizes 1 \
    --max-n-tokens 200 \
    --artifact-name llama3_2_1b \
    --n-model-chunk 4 \
    --output-folder /data/workdir/llama3_2_1b_output  \
    --build-folder /data/workdir/llama3_2_1b_build \
    --soc sa8295
```

llama3.2-1b weight sharing command:

```shell
python converter.py \
    --model-folder /home/sliu/Projects/New-Attempt/PowerServe/models_hf/llama3_2_1b \
    --model-name llama3_2_1b \
    --system-prompt-file /home/sliu/Projects/New-Attempt/PowerServe/assets/system_prompts/llama3.txt \
    --prompt-file /home/sliu/Projects/New-Attempt/PowerServe/assets/calibration_data/service_lab_intro_llama3.txt \
    --batch-sizes 1 16 \
    --max-n-tokens 200 \
    --artifact-name llama3_2_1b \
    --n-model-chunk 4 \
    --output-folder /data/workdir/llama3_2_1b_output_shared  \
    --build-folder /data/workdir/llama3_2_1b_build_shared \
    --soc sa8295
```

```shell
python converter.py \
    --model-folder /home/sliu/Projects/New-Attempt/PowerServe/models_hf/llama3_2_1b \
    --model-name llama3_2_1b \
    --system-prompt-file /home/sliu/Projects/New-Attempt/PowerServe/assets/system_prompts/llama3.txt \
    --prompt-file /home/sliu/Projects/New-Attempt/PowerServe/assets/calibration_data/service_lab_intro_llama3.txt \
    --batch-sizes 1 \
    --max-n-tokens 200 \
    --artifact-name llama3_2_1b \
    --n-model-chunk 4 \
    --output-folder /data/workdir/extra-mobile-qnn25/llama3_2_1b_output_bs1_no_share  \
    --build-folder /data/workdir/extra-mobile-qnn25/llama3_2_1b_build_bs1_no_share \
    --soc sa8295

python ./tools/gguf_export.py -m /home/sliu/Projects/New-Attempt/PowerServe/models_hf/llama3_2_1b --qnn-path /data/workdir/extra-mobile-qnn25/llama3_2_1b_output_bs1_no_share -o /data/workdir/extra-mobile-qnn25/llama3_2_1b_bs1_no_share

./powerserve create -m /data/workdir/extra-mobile-qnn25/llama3_2_1b_bs1_no_share --exe-path ./build_mobild_qnn/out -o /data/workdir/extra-mobile-qnn25/working_1b_bs1_no_share
```

Llama3.2-3B command:

```sh
python converter.py \
    --model-folder /home/sliu/Projects/New-Attempt/PowerServe/models_hf/llama3_2_3b \
    --model-name llama3_2_3b \
    --system-prompt-file /home/sliu/Projects/New-Attempt/PowerServe/assets/system_prompts/llama3.txt \
    --prompt-file /home/sliu/Projects/New-Attempt/PowerServe/assets/calibration_data/service_lab_intro_llama3.txt \
    --batch-sizes 1 \
    --max-n-tokens 200 \
    --artifact-name llama3_2_3b \
    --n-model-chunk 7 \
    --output-folder /data/workdir/llama3_2_3b_output  \
    --build-folder /data/workdir/llama3_2_3b_build \
    --soc sa8295
```

```sh
python converter.py \
    --model-folder /home/sliu/Projects/New-Attempt/PowerServe/models_hf/llama3_2_3b \
    --model-name llama3_2_3b \
    --system-prompt-file /home/sliu/Projects/New-Attempt/PowerServe/assets/system_prompts/llama3.txt \
    --prompt-file /home/sliu/Projects/New-Attempt/PowerServe/assets/calibration_data/service_lab_intro_llama3.txt \
    --batch-sizes 1 \
    --max-n-tokens 200 \
    --artifact-name llama3_2_3b \
    --n-model-chunk 7 \
    --output-folder /data/workdir/models_convert_3b/llama3_2_3b_output_bs1_no_share  \
    --build-folder /data/workdir/models_convert_3b/llama3_2_3b_build_bs1_no_share \
    --soc sa8295
    
python ./tools/gguf_export.py -m /home/sliu/Projects/New-Attempt/PowerServe/models_hf/llama3_2_3b --qnn-path /data/workdir/models_convert_3b/llama3_2_3b_output_bs1_no_share -o /data/workdir/models_convert_3b/llama3_2_3b_temp_bs1_no_share

./powerserve create -m /data/workdir/models_convert_3b/llama3_2_3b_temp_bs1_no_share --exe-path ./build/out -o /data/workdir/models_final/working_3b_bs1_no_share
```

# Model Statistics

You need to profile first, and save statistics as JSON files into a folder named `stat`, under the model folder.

- For attention: A list with attention head ids.
- For feed forward: A list with neuron ids.

These head/neuron ids should be sorted by importance (e.g. by quantization error) in descending order.

Example:

```bash
> ls -v1 /ssd/smallthinker_3b_20241220/stat
attn_0_stat.json
attn_1_stat.json
attn_2_stat.json
...
attn_35_stat.json
ffn_0_stat.json
ffn_1_stat.json
ffn_2_stat.json
...
ffn_35_stat.json
> cat /ssd/smallthinker_3b_20241220/stat/attn_0_stat.json
[13, 12, 10, 11, 9, 8, 14, 15, 2, 5, 1, 7, 4, 0, 3, 6]
```
