// student name:ÍõÏþÃ÷
// id number:202000130206

#include <omp.h>
#include <math.h>
#include <stdio.h>
using namespace std;

// add your codes begin
static long MULTIPLIER = 1366;
static long ADDEND = 150889;
static long PMOD = 714025;
long random_last = 0;
double randomm()
{
  long random_next;
  random_next = (MULTIPLIER * random_last + ADDEND) % PMOD;
  random_last = random_next;
  return ((double)random_next / (double)PMOD);
}
// add your codes end

int main()
{
  double pi, x, y, r = 1.0;
  long i, Ncirc = 0;
  double t = omp_get_wtime();
  int nthreads, id;
  unsigned long long pseed[256];
// add your codes begin
#pragma omp single
  {
    nthreads = omp_get_num_threads();
    unsigned long long iseed = PMOD / MULTIPLIER; // just pick a seed
    pseed[0] = iseed;
    unsigned long long mult_n = MULTIPLIER;
    for (int i = 1; i < nthreads; ++i)
    {
      iseed = (unsigned long long)((MULTIPLIER * iseed) % PMOD);
      pseed[i] = iseed;
      mult_n = (mult_n * MULTIPLIER) % PMOD;
    }
  }
  id = omp_get_thread_num();
  random_last = (unsigned long long)pseed[id];

#pragma omp parallel for private(x, y) reduction(+ \
                                                 : Ncirc)
  for (i = 0; i < SIZE; i++)
  {
    x = randomm();
    y = randomm();
    if (x * x + y * y <= r * r)
      Ncirc++;
  }
  pi = 4.0 * ((double)Ncirc / (double)SIZE);
  // add your codes end
  t = omp_get_wtime() - t;
  printf("time %f %d\n", t, SIZE);

  printf("pi %.12f %.12f\n", pi, pi - M_PI);
}
