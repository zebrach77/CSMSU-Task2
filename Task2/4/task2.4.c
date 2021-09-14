#include <stdio.h>


int char2intDigit(char c)
{
  return c-'0';
}


double str2double(char str[])
{
  int ind1;
  double res = 0, temp=1;
  ind1 = 0;
  //integer part
  while (str[ind1] != '.')
  {
    res = (res * 10.0) + char2intDigit(str[ind1]);
  }
  //double part
  for (int i = ind1; i<(int) sizeof(str)/sizeof(str[0]); ++i)
  {
    temp /= 10.0;
    res += char2intDigit(str[i])*10;
  }
  return res;
}


int main()
{
  char temp[];
  while(scanf("%s", &temp)!=EOF)
  {
    printf("%.10g\n", str2double(temp)));
  }
}
