// student name:王晓明
// id number:202000130206
#include <omp.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  vector<bool> is_prime(SIZE + 1, true); // 标记数组，is_prime[i] = true 表示 i 是素数
  vector<long> prime;                    // 存放素数

  // 计时开始
  double t = omp_get_wtime();

#pragma omp parallel for schedule(dynamic, 1000) // 使用动态调度和大小为 1000 的块，进行并行化
  for (long i = 2; i < (long)sqrt(SIZE); i++)
  { // 对于 [2, sqrt(SIZE)] 中的每一个数
    if (is_prime[i])
    { // 如果该数是素数
      for (long j = i * i; j <= SIZE; j += i)
      { // 则将其倍数标记为非素数
        is_prime[j] = false;
      }
    }
  }

  // 将所有素数存入 prime 中
  for (long i = 2; i <= SIZE; i++)
  {
    if (is_prime[i])
    {
      prime.push_back(i);
    }
  }

  // 计时结束
  t = omp_get_wtime() - t;

  // 输出结果
  printf("prime");
  sort(prime.begin(), prime.end());
  for (long i = 0; i < prime.size(); i++)
    printf(" %ld", prime[i]);
  printf("\nsize %ld\n", prime.size());
  printf("time %f %ld\n", t, long(SIZE));
}
