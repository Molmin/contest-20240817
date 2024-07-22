set -e

g++ generator.cpp -o generator.tmp -std=c++14 -O2
cp ../code/jiazhichen844.cpp std.tmp.cpp
g++ std.tmp.cpp -o std.tmp -std=c++14 -O2

for i in {1..2}
do
    for j in {1..20}
    do
        echo $i $j
        echo $i $j >id.tmp
        ./generator.tmp <id.tmp >result/$i-$j.in
        time timeout 1 ./std.tmp <result/$i-$j.in >result/$i-$j.ans
    done
done

zip data.zip *.in
zip data.zip *.ans
