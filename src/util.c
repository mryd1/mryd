#include <stdio.h>
double sum(double *arrays, int length)
{
  int i;
  double sum = 0;
  for (i = 0; i < length; i++)
  {
    sum += arrays[i];
  }
  return sum;
}
double average(double *arrays, int length)
{
  return sum(arrays, length) / length;
}
double total(double score1, double score2, double per1, double per2)
{
  return score1 * per1 + score2 * per2;
}
double sd(double *arrays,int length)
{
  //自己写
}
double percent(double *arrays,int length,double key)
{
  //自己写
  return 0;
}
double getMax(double *arrays,int length)
{
  //自己写
  return 0;
}
double getMin(double *arrays,int length)
{
  //自己写
  return 0;
}