set -e

g++ generator.cpp -o generator.tmp -std=c++14 -O2

for i in {1..4}
do
    for j in {1..3}
    do
        echo $i $j
        echo $i $j >id.tmp
        ./generator.tmp <id.tmp >result/$i-$j.in
    done
done

zip data.zip result/*.in
