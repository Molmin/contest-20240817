set -e

cp $1 foo.tmp.cpp
echo "Compiling $1"
g++ foo.tmp.cpp -o foo.tmp -std=c++14 -O2

for i in $(seq $2 $3)
do
    for j in {1..20}
    do
        echo "Running Subtask $i Test $j"
        time timeout 0.3 ./foo.tmp <data/result/$i-$j.in >output.tmp
        diff output.tmp data/result/$i-$j.ans -Z
    done
done
