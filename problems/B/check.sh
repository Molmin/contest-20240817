set -e

cd data
cp ../../../testlib.h testlib.h
echo "Compiling Validator"
g++ validator.cpp -o validator.tmp -std=c++14 -O2
bash generator.sh
cd ..

bash judge.sh code/subtask1.cpp 1 1
bash judge.sh code/subtask2.cpp 1 2
bash judge.sh code/subtask3.cpp 3 3
bash judge.sh code/subtask4.cpp 4 4
bash judge.sh code/std.cpp 1 5
