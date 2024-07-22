set -e

cd data
bash generator.sh
cp ../../../testlib.h testlib.h
echo "Compiling Checker"
g++ checker.cpp -o checker.tmp -std=c++14 -O2
cd ..

bash judge.sh code/bf.cpp 0 5
bash judge.sh code/bf_bitset.cpp 0 6
bash judge.sh code/dfs.cpp 1 8
bash judge.sh code/bruckets.cpp 2 8
bash judge.sh code/mod/mod_one_prime.cpp 1 9
bash judge.sh code/mod/mod_two_primes.cpp 1 9
bash judge.sh code/two_parts_random.cpp 1 10
bash judge.sh code/meet_in_the_middle.cpp 2 10
bash judge.sh code/mod/mod_1e6.cpp 2 10
bash judge.sh code/mod/mod_bitset.cpp 4 11
