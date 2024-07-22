set -e

cd data
bash generator.sh
echo "Compiling Communicator"
g++ result/communicator.cpp -o ../communicator.tmp -std=c++14 -O2
cd ..

bash judge.sh code/subtask1.cpp 1 1
bash judge.sh code/subtask3.cpp 3 3
bash judge.sh code/std.cpp 1 4
