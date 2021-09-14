#include <stdio.h>


double gornerCalc (double x, double a1, double a2)
{
  return a1 * x + a2;
}
//1 2 3
//5
//(5+2)*5+3 = 38     1 7 38
//25+13



int main()
{
  double xnum, temp, res0, res1, n, resIntegralX;
  scanf("%lf", &n);
  scanf("%lf", &xnum);
  while (scanf("%lf", &temp) != EOF)
  {
    res1 = gornerCalc(xnum, res1, res0);
    res0 = gornerCalc(xnum, res0, temp);
    resIntegralX = gornerCalc(xnum, resIntegralX, temp/(n+1));
    --n;
  }
  printf("%lf\n", res0);
  printf("%lf\n", res1);
  printf("%lf\n", resIntegralX*xnum);
}
