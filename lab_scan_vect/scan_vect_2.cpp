#include <omp.h>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <iostream>
using namespace std;
// add your codes begin
int num;
const int maxn = 10000000;
vector<int> pre_sum(maxn, 1), tmp(maxn, 1);

void scan_recursion(int step)
{
    if (step == num)
    {
        return;
    }
#pragma omp paraller for
    for (int i = step * 2; i <= num; i += (step * 2))
    {
        tmp[i] = pre_sum[i] + pre_sum[i - step];
    }
#pragma omp paraller for
    for (int i = step * 2; i <= num; i += (step * 2))
    {
        pre_sum[i] = tmp[i];
    }
    scan_recursion(step * 2);
#pragma omp paraller for
    for (int i = step * 2 + step; i < num; i += (step * 2))
    {
        tmp[i] = pre_sum[i] + pre_sum[i - step];
    }
#pragma omp paraller for
    for (int i = step * 2 + step; i < num; i += (step * 2))
    {
        pre_sum[i] = tmp[i];
    }
}
// add your codes end

int main()
{
    double t = omp_get_wtime();
    // add your codes begin
    num = 1;
    while (num < (SIZE - 1))
    {
        num *= 2;
    }
    scan_recursion(1);
    pre_sum[0] = 0;
    // add your codes end
    t = omp_get_wtime() - t;
    printf("time %f %d\n", t, SIZE);

    for (int i = 0; i < SIZE; i++)
        assert(pre_sum[i] == i);
}