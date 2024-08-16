set -e

unzip foo >/dev/null
rm communicator.cpp compile.sh execute.sh foo
./communicator 1 >input
./user <input >output
./communicator 2
./user <input
