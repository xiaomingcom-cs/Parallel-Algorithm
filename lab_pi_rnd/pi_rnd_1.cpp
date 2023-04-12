//student name:
//id number:

#include <omp.h>
#include <math.h>
#include <stdio.h>
using namespace std;


// add your codes begin
// add your codes end


int main() {
  double pi;

  double t = omp_get_wtime();
  // add your codes begin
  // add your codes end
  t = omp_get_wtime() - t;
  printf("time %f %d\n", t, SIZE);

  printf("pi %.12f %.12f\n", pi, pi-M_PI);
}

