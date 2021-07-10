//工具函数文件
#ifndef UTIL_H_
#define UTIL_H_
/**
 * 求和函数
 * -------
 * 参数说明
 * arrays 要求和的数组
 * length 要求和的长度
 * -------
 * 返回值
 * 指定长度的和
 */
double sum(double *arrays, int length);
/**
 * 求平均函数
 * -------
 * 参数说明
 * arrays 要求平均的数组
 * length 要求平均的长度
 * -------
 * 返回值
 * 指定长度的平均值
 */
double average(double *arrays, int length);
/**
 * 计算总评成绩函数
 * -------
 * 参数说明
 * score1 平时成绩
 * score2 期末成绩
 * per1   平时成绩占比
 * per2   期末成绩占比
 * -------
 * 返回值
 * 总评成绩
 */
double total(double score1, double score2, double per1, double per2);
/**
 * 计算标准差
 * -------
 * 参数说明
 * arrays 要计算标准差的数组
 * length 要计算标准差的长度
 * -------
 * 返回值
 * 标准差
 */
double sd(double *arrays,int length);
/**
 * 计算数组中大于某个数的数量百分比
 * -------
 * 参数说明
 * arrays 参与计算的数组
 * length 参与计算的长度
 * key    某个数
 * -------
 * 返回值
 * 大于某个数的数量百分比
 */
double percent(double *arrays,int length,double key);
/**
 * 取数组最大值
 * -------
 * 参数说明
 * arrays 参与计算的数组
 * length 参与计算的长度
 * -------
 * 返回值
 * 最大值
 */
double getMax(double *arrays,int length);
/**
 * 取数组最小值
 * -------
 * 参数说明
 * arrays 参与计算的数组
 * length 参与计算的长度
 * -------
 * 返回值
 * 最小值
 */
double getMin(double *arrays,int length);
#endif
