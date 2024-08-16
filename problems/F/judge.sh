set -e

cp $1 foo.tmp.cpp
echo "Compiling $1"
g++ foo.tmp.cpp -o foo.tmp -std=c++14 -O2

arr=(7 3 3 3 30 30)

for i in $(seq $2 $3)
do
    for j in $(seq 1 ${arr[i-1]})
    do
        echo "Running Subtask $i Test $j"
        time timeout 1 ./foo.tmp <data/result/$i-$j.in >output.tmp
        ./data/checker.tmp data/result/$i-$j.in output.tmp /dev/null
    done
done
