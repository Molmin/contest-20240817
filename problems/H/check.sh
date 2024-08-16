set -e

cd data
cp ../../../testlib.h testlib.h
echo "Compiling Checker"
g++ checker.cpp -o checker.tmp -std=c++14 -O2
cd ..

bash judge.sh code/std.cpp 1 10
bash judge.sh code/DeaphetS.cpp 1 10
