double sum(double *arrays, int length)
{
  int i, sum = 0;
  for (i = 0; i < length; i++)
  {
    sum += arrays[i];
  }
}
double average(double *arrays, int length)
{
  return sum(arrays, length) / length;
}
double total(double score1, double score2, double per1, double per2)
{
  return score1 * per1 + score2 * per2;
}
