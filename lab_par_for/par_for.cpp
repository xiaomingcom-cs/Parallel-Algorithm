#include <omp.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
 int SIZE = 10;
 int test[SIZE];
  #pragma omp parallel for schedule(dynamic, 4)
  for (int i = 0; i < SIZE; i++) {
    test[i] = omp_get_thread_num();
  }
  for (int i = 0; i < SIZE; i++) {
    printf(" %d", test[i]);
  }
  printf(" %d\n", SIZE);
}

