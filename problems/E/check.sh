set -e

cd data
bash generator.sh
cp ../../../testlib.h testlib.h
echo "Compiling Checker"
g++ checker.cpp -o checker.tmp -std=c++14 -O2
cd ..

bash judge.sh code/std.cpp 1 7
