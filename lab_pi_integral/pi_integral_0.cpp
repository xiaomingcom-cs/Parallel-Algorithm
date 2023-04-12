//student name:
//id number:

#include <omp.h>
#include <math.h>
#include <stdio.h>
using namespace std;


// add your codes begin
double claPI(){
  double PI,x,step,sum=0.0;
  step = 1.0/(double)SIZE;
  for(int i =0; i<SIZE; i++){
    x = (i+0.5)*step;
    sum = sum + 4.0/(1.0+x*x);
  }
  PI = step * sum;
  return PI;
}
// add your codes end


int main() {
  double pi;

  double t = omp_get_wtime();
  // add your codes begin
  pi  = claPI();
  // add your codes end
  t = omp_get_wtime() - t;
  printf("time %f %d\n", t, SIZE);

  printf("pi %.12f %.12f\n", pi, pi-M_PI);
}

