- Student name:王晓明
- ID number:202000130206

- Implement your scan algorithm
  - Version 0: serial program
  - Version 1: brute-force program
  - Version 2: recursion program
- Compile and run your programs multiple times
- Describe your observations
- Explain why this happens

-版本0进行串行运算，每次都在原有前缀和的基础上加上一个新元素
-版本1对数组中的每个元素执行一次reduce操作，其中map和reduce操作均可以并行化，但是与版本0相比，增加了冗余运算量，数组每个位置对应的前缀和是单独求的，没有充分利用前面位置已经算出来的结果，因此速度最慢
-版本2通过递归和par-for避免了冗余计算，在cpu核数足够大的时候复杂度可以优化到logn，当核数比较少的时候由于线程创建开销和算法本身复杂度略高而慢于版本0
