//student name:
//id number:

#include <omp.h>
#include <math.h>
#include <stdio.h>
using namespace std;


// add your codes begin
#define PAD 8
#define NUM_THREADS 20
// add your codes end


int main() {
  double pi;

  double t = omp_get_wtime();
  // add your codes begin
  int nthreads,i;
  double step,sum[NUM_THREADS][PAD];
  step = 1.0/(double)SIZE;
  omp_set_num_threads(NUM_THREADS);
  #pragma omp parallel
  {
    int i,id,nthrds;
    double x;
    id = omp_get_thread_num();
    nthrds = omp_get_num_threads();
    if(id == 0) nthreads = nthrds;
    for(i=id, sum[id][0]=0.0; i<SIZE; i+=nthrds){
	x=(i+0.5)*step;
    	sum[id][0] += 4.0/(1.0+x*x);
    }	
  } 
  for(i=0,pi=0.0; i<nthreads;i++) pi+=sum[i][0]*step;
  // add your codes end
  t = omp_get_wtime() - t;
  printf("time %f %d\n", t, SIZE);

  printf("pi %.12f %.12f\n", pi, pi-M_PI);
}

