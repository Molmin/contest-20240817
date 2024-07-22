set -e

cp $1 foo.tmp.cpp
g++ foo.tmp.cpp -o foo.tmp -std=c++14 -O2

for i in {1..4}
do
    for j in {1..5}
    do
        time timeout 1 ./foo.tmp <data/result/$i-$j.in >output.tmp
        ./data/checker.tmp data/result/$i-$j.in output.tmp /dev/null
    done
done

for i in {5..11}
do
    for j in {1..5}
    do
        time timeout 1 ./foo.tmp <data/result/$i-$j.in >output.tmp
        ./data/checker.tmp data/result/$i-$j.in output.tmp /dev/null
    done
done
