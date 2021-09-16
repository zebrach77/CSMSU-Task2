#include <stdio.h>


double sqrtViaNewton(double xPrevious, double epsilon, double x)
{
  if (xPrevious == 0)
  {
    fprintf(stderr, "%s", "Error!!! Division by zero!!!\n");
    return -1;
  }
  double xCurrent = 0.5*(xPrevious+(x/xPrevious));
  if (xCurrent>xPrevious)
  {
    if (xCurrent-xPrevious<epsilon)
    {
      return xCurrent;
    }

    else
    {
      return sqrtViaNewton(xCurrent, epsilon, x);
    }
  }
  else
  {
    if (xPrevious-xCurrent<epsilon)
    {
      return xCurrent;
    }

    else
    {
      return sqrtViaNewton(xCurrent, epsilon, x);
    }
  }
}



int main()
{
  double temp;
  double eps;
  scanf("%lf", &eps);
  while (scanf("%lf", &temp) != EOF)
  {
    printf("%lf\n", sqrtViaNewton(1, eps, temp));
  }
}
