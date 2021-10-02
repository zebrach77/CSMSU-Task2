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
  res0 = 0;
  res1 = 0;
  resIntegralX = 0;
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


/*
 * For those people who can't find formulas for the derivative and integral:
 * After computing the value of a polynomial in a point we have the following coefficients:
 * Was: a0 X^n + a1 X^(n-1) + ... + an | and we divide this polynomial into (X-x0)
 * We got: b0 X^(n-1) + b1 X^(n-2) + ... + b(n-1) | and the res value k (modulo)
 * Now, to compute the first derivative of the polynomial we have to do the same operation with the polynomial that we got, e.g.
 * we divide this polynomial into (X-x0) again, and the modulo will be our result.
 * Note: If you want to compute the second, third, etc.  derivative of the polynomial, we should multiply the result by the factorial of the number of the derivative
 *
 *
 * Integral from 0 to x can be computed with the following polynomial:
 * Was: a0 X^n + a1 X^(n-1) + ... + an
 * Compute: a0/n X^(n+1) + a1/(n) + ... + an/1 with the Gorner Scheme
 */
