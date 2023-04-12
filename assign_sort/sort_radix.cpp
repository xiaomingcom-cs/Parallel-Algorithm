// student name:
// id number:

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
  // add your codes end
  t = omp_get_wtime() - t;
  printf("time %f %d\n", t, SIZE);

  for (int i = 0; i < SIZE - 1; i++)
    assert(data[i] <= data[i + 1]);
}

#include <omp.h>
#define NPOINTS 1000
#define MXITR 1000
void testpoint(void);
struct d_complex
{
  double r;
  double i;
};
struct d_complex c;
int numoutside = 0;
int main()
{
  int i, j;
  double area, error, eps = 1.0e-5;
#pragma omp parallel for default(shared) private(c, eps)
  for (i = 0; i < NPOINTS; i++)
  {
    for (j = 0; j < NPOINTS; j++)
    {
      c.r = -2.0 + 2.5 * (double)(i) / (double)(NPOINTS) + eps;
      c.i = 1.125 * (double)(j) / (double)(NPOINTS) + eps;
      testpoint();
    }
  }
  area = 2.0 * 2.5 * 1.125 * (double)(NPOINTS * NPOINTS - numoutside) / (double)(NPOINTS * NPOINTS);
  error = area / (double)NPOINTS;
}
