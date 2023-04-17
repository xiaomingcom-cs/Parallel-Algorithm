// student name:ÍõÏþÃ÷
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
  int max_val = *max_element(data.begin(), data.end());
  omp_set_num_threads(64);
  int num_threads = omp_get_max_threads();
  for (int exp = 1; max_val / exp > 0; exp *= 10)
  {
    vector<int> output(SIZE);
    int count[10] = {0};
#pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < SIZE; i++)
    {
      int digit = (data[i] / exp) % 10;
#pragma omp atomic
      count[digit]++;
    }

    for (int i = 1; i < 10; i++)
      count[i] += count[i - 1];

    for (int i = SIZE - 1; i >= 0; i--)
    {
      int digit = (data[i] / exp) % 10;
      output[count[digit] - 1] = data[i];
#pragma omp atomic
      count[digit]--;
    }
#pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < SIZE; i++)
      data[i] = output[i];
  }
  // add your codes end
  t = omp_get_wtime() - t;
  printf("time %f %d\n", t, SIZE);

  for (int i = 0; i < SIZE - 1; i++)
    assert(data[i] <= data[i + 1]);
}
