#!/bin/bash
current_path=$(cd $(dirname $0); pwd)
parent_path=$(dirname ${current_path})
lib_path=${parent_path}/lib/rasa
bert_path=${parent_path}/Data/rasa/data/bert-base-chinese

python -m venv ${lib_path}
echo ${lib_path}/bin/activate
source ${lib_path}/bin/activate
pip install rasa
pip install jieba
pip install transformers
mkdir -p ${bert_path}
cd ${bert_path}
wget https://huggingface.co/google-bert/bert-base-chinese/resolve/main/config.json
wget https://huggingface.co/google-bert/bert-base-chinese/resolve/main/pytorch_model.bin
wget https://huggingface.co/google-bert/bert-base-chinese/resolve/main/tf_model.h5
wget https://huggingface.co/google-bert/bert-base-chinese/resolve/main/tokenizer_config.json
wget https://huggingface.co/google-bert/bert-base-chinese/resolve/main/vocab.txt
