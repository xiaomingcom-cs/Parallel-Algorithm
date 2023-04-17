// student name:ÍõÏşÃ÷
// id number:202000130206

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

int main()
{
  vector<int> data(SIZE);

  srand(SIZE);
  for (int i = 0; i < SIZE; i++)
    data[i] = rand() % (SIZE * 10);

  double t = omp_get_wtime();
  // add your codes begin
  vector<int> tmp(SIZE);
  sort(data.begin(), data.begin() + 64 * 8);
  omp_set_num_threads(64);
  int nthreads;
#pragma omp parallel
  {
    int id, nthrds;
    id = omp_get_thread_num();
    nthrds = omp_get_num_threads();
    if (id == 0)
      nthreads = nthrds;
    int l = 0, r = 2e9, idxl = 0, idxr;
    if (id != 0)
      l = data[8 * id];
    if (id != nthrds - 1)
      r = data[8 * (id + 1)];
    for (int i = 0; i < SIZE; i++)
      if (data[i] < l)
        ++idxl;

    idxr = idxl;
    for (int i = 0; i < SIZE; i++)
      if (data[i] >= l && data[i] < r)
        tmp[idxr++] = data[i];
    sort(tmp.begin() + idxl, tmp.begin() + idxr);

#pragma omp barrier
    for (int i = idxl; i < idxr; i++)
      data[i] = tmp[i];
  }
  // add your codes end
  t = omp_get_wtime() - t;
  printf("time %f %d\n", t, SIZE);

  for (int i = 0; i < SIZE - 1; i++)
    assert(data[i] <= data[i + 1]);
}
