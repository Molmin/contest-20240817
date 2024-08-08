set -e

g++ generator.cpp -o generator.tmp -std=c++14 -O2
cp ../code/std.cpp std.tmp.cpp
g++ std.tmp.cpp -o std.tmp -std=c++14 -O2

arr=(8 8 16 16 16 16 5 24)

for i in {1..8}
do
    for j in $(seq 1 ${arr[i-1]})
    do
        echo $i $j
        echo $i $j >id.tmp
        ./generator.tmp <id.tmp >result/$i-$j.in
        time timeout 0.5 ./std.tmp <result/$i-$j.in >result/$i-$j.ans
    done
done

zip data.zip result/*.in
zip data.zip result/*.ans
