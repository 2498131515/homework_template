# 实验报告

## 学号：20201060373

>注:为保护同学隐私，请不要填写姓名

## 实验目的：

通过排序算法的程序实现和执行时间测试，与理论上的结论进行对比分析，深入理解算法时间复杂度渐进性态和和增长率的概念；理解分治算法设计的基本
思想、递归程序实现的基本方法，加深对分治算法设计与分析思想的理解。

## 实验原理




## 实验输入数据集

文本数据集：10 100 2000 5000 10000 10000
增长图：[增长图](./data/res.png)
文件数据集：[数据集](./data/list.txt)

## 实验内容

以冒泡排序、合并排序和快速排序算法为例，以生成的随机数作为实验中使
用的测试数据。对每个算法，记录程序执行中随着测试数据增加算法基本操作执
行次数，分析并以图形方式展现增长率；对以上三个排序算法，对比随着测试数
据增加算法增长率变化趋势；测试、验证、对比算法时间复杂度的理论结论。
1.[分治法](./dac.c)

## 实验预期结果与实际结果
预期冒泡排序的增长速度远大于快速排序与归并排序


实际：
数据量 冒泡 快速 归并：
10 18,23,24
100 2348 583 550
2000 1008869 23808 19391
5000 6281230 67768 55240
10000 25047229 161157 120423
100000 超界 190050 1536455