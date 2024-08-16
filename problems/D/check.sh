set -e

cd data
bash generator.sh
echo "Compiling Communicator"
g++ result/communicator.cpp -o ../communicator.tmp -std=c++14 -O2
cd ..

bash judge.sh code/std.cpp 1 5
bash judge.sh code/jiazhichen844.cpp 1 5
