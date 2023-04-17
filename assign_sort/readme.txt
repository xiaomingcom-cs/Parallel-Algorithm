- Student name:
- ID number:

- Implement your sort algorithm
  - Version 1: radix sort program
  - Version 2: sample sort program
- Compile and run your programs multiple times
- Describe your observations
- Explain why this happens

radix sort:
  在多次运行程序时，由于线程数量和分配方式的不同，可能会出现不同的运行时间。
  如果使用的线程数量与计算机的处理器核心数相同，且每个线程被分配到了相同数量的工作量，那么运行时间可能会最短。
  但是，如果线程数量太多，而每个线程被分配的工作量太少，线程之间的通信和同步可能会导致额外的开销，使运行时间变长。
  另一方面，如果线程数量太少，那么某些处理器核心可能无法得到充分利用，从而浪费了计算资源。

sample sort:
  随着数据规模的增大，程序的运行时间也随之增大，但是增长速度越来越慢，甚至有时候增长速度会趋于平缓。
  这是因为随着随着数据规模的增加，单个线程所处理的数据量增加，线程间的负载不均衡也会更加明显，导致线程之间的同步和通信的开销增加，从而影响了程序的运行效率。
  但同时，当数据规模很大时，使用多线程并行计算可以充分利用多核处理器的优势，提高程序的运行速度。