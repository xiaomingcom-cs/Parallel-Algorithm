//student name:
//id number:

#define CUTOFF 1024

#include <omp.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


// add your codes begin
// add your codes end


int main() {
  vector<int> data(SIZE);

  srand(SIZE);
  for (int i = 0; i < SIZE; i++) data[i] = rand() % (SIZE * 10);

  double t = omp_get_wtime();
  // add your codes begin
  // add your codes end
  t = omp_get_wtime() - t;
  printf("time %f %d\n", t, SIZE);

  for (int i = 0; i < SIZE-1; i++) assert(data[i] <= data[i+1]);
}

