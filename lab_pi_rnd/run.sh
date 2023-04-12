version=0
size=1000

g++ -o pi_rnd_$version -fopenmp -DSIZE=$size pi_rnd_$version.cpp && timeout 60s time ./pi_rnd_$version

