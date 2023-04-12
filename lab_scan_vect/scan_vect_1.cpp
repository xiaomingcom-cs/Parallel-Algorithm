//student name:王晓明
//id number:202000130206

#include <omp.h>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <iostream>
using namespace std;


// add your codes begin
#define NUM_THREADS 4
vector<int> pre_sum(SIZE);
// add your codes end


int main() {
  vector<int> data(SIZE, 1);
  data[0] = 0;

  double t = omp_get_wtime();
  // add your codes begin
  omp_set_num_threads(NUM_THREADS);
#pragma omp parallel for //map
  for(int i=1;i<=SIZE;i++){
    int tmp_sum = 0;
#pragma omp parallel for reduction(+:tmp_sum) //reduce
    for(int j=1;j<=i;j++){
      tmp_sum = tmp_sum+data[j];
    }
    pre_sum[i]=tmp_sum; 
  }
  // add your codes end
  t = omp_get_wtime() - t;
  printf("time %f %d\n", t, SIZE);

  for (int i = 0; i < SIZE; i++) assert(pre_sum[i]==i);
}


