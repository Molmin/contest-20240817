set -e

g++ generator.cpp -o generator.tmp -std=c++14 -O2
g++ convert.cpp -o convert.tmp -std=c++14 -O2

for i in {1..5}
do
    for j in {1..4}
    do
        echo $i $j
        echo $i $j >id.tmp
        ./generator.tmp <id.tmp >result/$i-$j.in
        ./convert.tmp <result/$i-$j.in >result/$i-$j.ans
    done
done

zip data.zip result/*.in
zip data.zip result/*.ans
