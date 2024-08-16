set -e

cp $1 foo.tmp.cpp
echo "Compiling $1"
g++ foo.tmp.cpp -o foo.tmp -std=c++14 -O2

for i in $(seq $2 $3)
do
    for j in {1..4}
    do
        echo "Running Subtask $i Test $j"
        cp data/result/$i-$j.in input.tmp
        bash execute.sh >output2.tmp
        diff output2.tmp data/result/$i-$j.ans -Z
    done
done
