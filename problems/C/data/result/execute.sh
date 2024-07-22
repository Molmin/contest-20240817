set -e

unzip foo >/dev/null
rm communicator.cpp compile.sh execute.sh foo
./communicator 1
./user <input1.tmp >output1.tmp
./communicator 2
./user <input2.tmp
