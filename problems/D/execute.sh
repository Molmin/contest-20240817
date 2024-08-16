./communicator.tmp 1 <input.tmp >input
time timeout 1 ./foo.tmp <input >output
./communicator.tmp 2
time timeout 1 ./foo.tmp <input
rm input output
