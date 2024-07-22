./communicator.tmp 1 <input.tmp
time timeout 0.5 ./foo.tmp <input1.tmp >output1.tmp
./communicator.tmp 2
time timeout 0.5 ./foo.tmp <input2.tmp
