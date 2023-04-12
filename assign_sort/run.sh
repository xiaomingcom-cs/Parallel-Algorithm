version=radix
size=1000

g++ -o sort_$version -fopenmp -DSIZE=$size sort_$version.cpp && timeout 60s time ./sort_$version

