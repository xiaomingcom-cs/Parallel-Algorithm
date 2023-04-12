- Student name:王晓明
- ID number:202000130206

- Watch lectures: https://icloud.qd.sdu.edu.cn:7777/link/2D2A742C095E0CFD13FEB87F405E2FEB
- Expiration date: 2023-06-18
- Implement your Pi program "pi_integral_N.cpp" of Unit 2
  - Version 0: serial program
  - Version 1: parallel program using parallel-for and reduction
  - Version 2: parallel program without using parallel-for 
- Compile and run your programs multiple times
- Describe your observations
- Explain why this happens

- version1和version2的运行时间在设置的线程数较小的情况下会慢于version0的串行算法，因为线程并行带来的时间优化不足以抵消创建线程的开销；当线程数较大时两个版本的并行算法会快于串行算法，而且每次运行时间都不同；
- parallel for reduction(+:sum)会将下面的加操作分配个几个线程分别做私有变量上的操作，最后得到的县城结果再一起做一次操作(即reduce的并行算法)
- sum[][]设置第二维度(设置为cache line的长度)可以避免false sharing(如果数据元素在同一个cache line，每次数据更新会导致不必要的写回操作)，从而加快并行算法的执行过程
