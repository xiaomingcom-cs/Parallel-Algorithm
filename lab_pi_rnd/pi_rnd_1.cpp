//student name:ÍõÏþÃ÷
//id number:202000130206

#include <omp.h>
#include <math.h>
#include <stdio.h>
using namespace std;


// add your codes begin
static long MULTIPLIER = 1366;
static long ADDEND = 150889;
static long PMOD = 714025;
long random_last = 0;
#pragma omp threadprivate(random_last)
double randomm()
{
  long random_next;
  random_next = (MULTIPLIER * random_last + ADDEND) % PMOD;
  random_last = random_next;
  return ((double)random_next / (double)PMOD);
}
// add your codes end


int main() {
  double pi,x,y,r=1.0;
  long i, Ncirc = 0;
  double t = omp_get_wtime();
  // add your codes begin
  #pragma omp parallel for private(x,y) reduction (+:Ncirc)
  for (i = 0; i < SIZE; i++)
  {
    x = randomm();
    y = randomm();
    if(x*x+y*y<=r*r)
      Ncirc++;
  }
  pi = 4.0 * ((double)Ncirc / (double)SIZE);
  // add your codes end
  t = omp_get_wtime() - t;
  printf("time %f %d\n", t, SIZE);

  printf("pi %.12f %.12f\n", pi, pi-M_PI);
}

