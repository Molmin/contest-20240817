set -e

g++ generator.cpp -o generator.tmp -std=c++14 -O2

for i in {1..11}
do
    for j in {1..5}
    do
        echo $i $j >testid.tmp
        ./generator.tmp <testid.tmp >result/$i-$j.in
    done
done

zip data.zip result/*.in
