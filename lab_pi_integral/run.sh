version=2
size=1000000

g++ -o pi_integral_$version -fopenmp -DSIZE=$size pi_integral_$version.cpp && timeout 60s time ./pi_integral_$version

