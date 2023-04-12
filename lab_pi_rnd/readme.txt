- Student name:王晓明
- ID number:202000130206

- Implement your Pi program "pi_rnd_N.cpp"
  - Version 0: serial program using LCG PRNG
  - Version 1: parallel program using thread-safe PRNG
  - Version 2: parallel program using leap-frog PRNG
- Compile and run your programs multiple times
- Describe your observations
- Explain why this happens

发现：thread-safe version每次运行代码的时候结果相同，但是当数据量较大的时候，准确度低于单线程; leap-frog对于不同的线程数量会产生相同的PI结果

原因：对于thread-safe version,每次计算PI的时候，每个线程的起始种子值都相同，并且每个线程生成的随机数序列长度相同，则每个线程生成的坐标点的顺序也是相同的，因此最终计算得到的PI值也是相同的。
由于线程间的竞争，可能会导致随机数的重复使用，从而导致计算出的圆周率不准确。为解决这个问题引入leap-frog version,将随机数序列的值像发牌一样“依次分发”，使每个线程生成的随机数序列是不同的，不会产生重叠问题。
leep-frog version的基本思想是将随机数序列分为若干个段，让不同线程在不同的段中生成随机数，从而避免了不同线程生成相同的随机数的问题，因此也避免了重叠问题。
然而，无论线程数如何变化，对于同一组种子值，leep-frog都会以相同的方式划分随机数序列并生成相同的随机数值。这是因为跳跃法中的跳跃步长（称为跳跃值或步长值）是由种子值确定的，因此不同的线程数并不会改变跳跃步长的大小。当种子值相同且跳跃步长相同时，不同线程生成的随机数序列和随机数值也相同，因此即使线程数发生变化，也会产生相同的答案。