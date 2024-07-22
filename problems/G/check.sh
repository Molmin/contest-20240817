set -e

cd data
bash generator.sh
cp ../../../testlib.h testlib.h
g++ checker.cpp -o checker.tmp -std=c++14 -O2
cd ..

bash judge.sh code/mod/mod_1e6.cpp 4 9
