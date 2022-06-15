# 实验报告

## 学号：20201060373


## 实验目的：

1.通过排序算法的程序实现和执行时间测试，与理论上的结论进行对比分析，深入理解算法时间复杂度渐进性态和和增长率的概念；理解分治算法设计的基本思想、递归程序实现的基本方法，加深对分治算法设计与分析思想的理解。
2.1编程实现经典的动态规划算法，理解动态规划算法设计的基本思想、程序实现的相关技巧，加深对动态规划算法设计与分析思想的理解。通过程序的执行时间测试结果，与理论上的时间复杂度结论进行对比、分析和验证。
2.2

## 实验原理

1.算法的计算时间取决于算法中某些操作的执行次数，这些操作是算法时间复杂度分析的依据。增长率反映了算法的计算时间复杂度，即随着算法输入规模的增加、算法计算时间增加的趋势。算法的计算时间复杂度针对输入数据的等价类来分析或测试。
2.1动态规划是一种在数学和计算机科学中使用的、用于求解包含重叠子问题的最优化问题的有效方法。其基本思想是：将原问题分解为相似的子问题，在求解
的过程中通过子问题的解描述并求出原问题的解。动态规划的思想是多种算法的基础，被广泛应用于计算机科学和工程领域，在查找有很多重叠子问题的情况的最优解时有效。它将问题重新组合成子问题，为了避免多次解决这些子问题，它们的结果都逐渐被计算并保存，从小规模的子问题直到整个问题都被解决。因此，动态规划对每一子问题只做一次计算，具有较高的效率。
算法的时间复杂度为O(nC)。


## 实验输入数据集

1.文本数据集：10 100 2000 5000 10000 10000
增长图：[增长图](./data/res.png)
文件数据集：[数据集](./data/list.txt)
2.数据大小：n：10 100 2000 4000 20000
           c:200 2000 4000 20000
花费时间图：

## 实验内容

1.以冒泡排序、合并排序和快速排序算法为例，以生成的随机数作为实验中使用的测试数据。对每个算法，记录程序执行中随着测试数据增加算法基本操作执行次数，分析并以图形方式展现增长率；对以上三个排序算法，对比随着测试数据增加算法增长率变化趋势；测试、验证、对比算法时间复杂度的理论结论。
分治法：[分治法](./dac.c)
2.1编程实现以上求解0-1 背包问题的动态规划算法，并通过手动设置、生成随机数获得实验数据。记录随着输入规模增加算法的执行时间，分析并以图形方式展现增长率；测试、验证、对比算法的时间复杂度。
01背包：[01背包]：(./0-1bag.c)

## 实验预期结果与实际结果

1.预期冒泡排序的增长速度远大于快速排序与归并排序，快排和归并增长速度相近
实际：
数据量 冒泡 快速 归并：
10 18,23,24
100 2348 583 550
2000 1008869 23808 19391
5000 6281230 67768 55240
10000 25047229 161157 120423
100000 超界 190050 1536455
从拟合图像和数据都可得出，冒泡排序增长速度远大于其他两种排序算法，并且其他两种算法的时间复杂度相近
2.1