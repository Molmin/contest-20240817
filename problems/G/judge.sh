set -e

cp $1 foo.tmp.cpp
echo "Compiling $1"
g++ foo.tmp.cpp -o foo.tmp -std=c++14 -O2

for i in $(seq 1 $2)
do
    for j in {1..5}
    do
        echo "Running Subtask $i Test $j"
        time timeout 1 ./foo.tmp <data/result/$i-$j.in >output.tmp
        ./data/checker.tmp data/result/$i-$j.in output.tmp /dev/null
    done
done

for i in $(seq 5 $3)
do
    for j in {1..5}
    do
        echo "Running Subtask $i Test $j"
        time timeout 1 ./foo.tmp <data/result/$i-$j.in >output.tmp
        ./data/checker.tmp data/result/$i-$j.in output.tmp /dev/null
    done
done
