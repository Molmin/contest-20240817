set -e

if [ $HYDRO_LANG = "cc.cc14o2" ] ; then
  g++ foo.cc -o user -std=c++14 -O2
else
  g++ foo.cc -o user -std=c++17 -O2
fi

g++ communicator.cpp -o communicator -std=c++14 -O2
zip data user communicator >/dev/null
mv data.zip foo
