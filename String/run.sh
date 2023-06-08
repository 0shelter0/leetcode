
echo "usage of running demo.cpp: bash run.sh demo"
script_dir=$(cd $(dirname $0);pwd)    
# echo ${script_dir}
FILENAME=$1
path=${script_dir}/${FILENAME}.cpp
echo "target file: "${path}
g++ ${path} -o ${script_dir}/$1
${script_dir}/$1