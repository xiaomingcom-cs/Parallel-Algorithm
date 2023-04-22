- Student name:
- ID number:

- Implement your fragment scan algorithm
- Compile and run your programs multiple times
- Describle how you incrementally implement and test your program

1.实现顺序扫描算法
首先，我会实现顺序扫描算法，并手动计算一些输入数据的预期结果，以确保算法的正确性。例如，对于输入数据data = [1, 2, 3, 4, 5]和flag = [0, 0, 1, 0, 1]，预期结果为[1, 3, 3, 7, 12]。

2.添加OpenMP指令
接下来，我会添加OpenMP指令，并使用#pragma omp parallel for并行化算法。为了确保不会出现数据竞争等问题，我会在指令前添加#pragma omp parallel default(none) shared(data, flag, SIZE)，并在循环中使用private和firstprivate指令，以确保每个线程都拥有自己的私有变量，并在循环开始时将其初始化。例如：
#pragma omp parallel default(none) shared(data, flag, SIZE) private(i) firstprivate(dist)
{
  for (i = (dist << 1) - 1; i < SIZE; i += (dist << 1))
  {
    if (flag[i])
      continue;
    #pragma omp atomic
    data[i] += data[i - dist];
    #pragma omp atomic
    flag[i] |= flag[i - dist];
  }
}
在这个例子中，i是私有变量，dist是在递归中传递的参数，而data、flag和SIZE是共享变量。为了避免竞争条件，我在修改data和flag时使用了#pragma omp atomic指令。

3.测试程序
最后，我会编写测试程序，并使用不同的输入数据进行测试。我通常会测试不同的输入大小、不同的flag分布、不同的线程数等情况，并使用性能分析工具（例如GNU Profiler）来检查程序的性能。如果发现性能瓶颈或错误，我会返回代码并进行相应的更改和优化。