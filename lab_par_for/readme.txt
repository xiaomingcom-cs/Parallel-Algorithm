- Watch lectures: https://icloud.qd.sdu.edu.cn:7777/link/2D2A742C095E0CFD13FEB87F405E2FEB
- Expiration date: 2023-06-18
- Implement your "Hello, World!" program "hello.cpp" of Unit 1

- Compile and run program "par_for.cpp" multiple times
- Describe your observations
- Explain why this happens

par_for.cpp
1. my observations：par_for.cpp执行结果是输出SIZE个数字，每四个数字是相同的，而且数字都是在0-63范围内的 
2. reason: 由于for schedule(dynamic,4)说明线程是动态调度的，每个线程执行4次for循环内部的语句之后调度下一个线程进行执行，由于服务器的CPU是64核的，因此thread_num是0-63范围内的数字
hello.cpp
1. hello(num)输出64次，num为0-63各出现一次，顺序是乱序的；world(num)同理也是，不过world(num)输出之后会输出换行，world(num)不一定在hello(num)之后输出，两者输出没有必然联系
2. reason: 由于#progma omp parallel 会让其范围内的语句分配到cpu的所有核心中执行，因此会输出64次，虽然程序并行执行，但是输出是串行的，因此会导致world(num)并不一定是在hello(num)后面输出
