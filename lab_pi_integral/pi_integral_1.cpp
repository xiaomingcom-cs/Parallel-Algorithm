//student name:王晓明
//id number:202000130206

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
  double sum=0.0,step = 1.0/(double)SIZE;
  omp_set_num_threads(20);
  #pragma omp parallel
  {
  	double x;
	#pragma omp for reduction(+:sum)
		for(int i=0;i<SIZE;i++){
			x=(i+0.5)*step;
			sum+=4.0/(1.0+x*x);
		}
  }
  pi = step * sum;
  // add your codes end
  t = omp_get_wtime() - t;
  printf("time %f %d\n", t, SIZE);

  printf("pi %.12f %.12f\n", pi, pi-M_PI);
}

