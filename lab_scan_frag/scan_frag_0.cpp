#include <omp.h>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <iostream>
using namespace std;
// add your codes begin
#define NUM_THREADS 64
void recursion(vector<int> &data, vector<int> &flag, int step)
{
  int i;
#pragma omp parallel for
  for (i = (step << 1) - 1; i < SIZE; i += (step << 1))
  {
    if (flag[i])
      continue;
    data[i] += data[i - step];
    flag[i] |= flag[i - step];
  }
  if ((step << 1) > SIZE)
    return;
  recursion(data, flag, step << 1);
#pragma omp parallel for
  for (i = step * 3 - 1; i < SIZE; i += (step << 1))
  {
    if (flag[i])
      continue;
    data[i] += data[i - step];
    flag[i] |= flag[i - step];
  }
}
// add your codes end
int main()
{
  vector<int> data(SIZE, 1);
  vector<int> flag(SIZE, 0);
  vector<int> test(SIZE);
  srand(SIZE);
  data[0] = 0;
  flag[0] = 1;
  for (int i = 0; i < flag.size() / 12; i++)
  {
    int index = rand() % flag.size();
    data[index] = 0;
    flag[index] = 1;
  }
  for (int i = 0; i < data.size(); i++)
    test[i] = (flag[i] != 0) ? data[i] : test[i - 1] + data[i];
  double t = omp_get_wtime();
  // add your codes begin
  omp_set_num_threads(NUM_THREADS);
  recursion(data, flag, 1);
  // add your codes end
  t = omp_get_wtime() - t;
  printf("time %f %d\n", t, SIZE);
  for (int i = 0; i < SIZE; i++)
    assert(data[i] == test[i]);
}