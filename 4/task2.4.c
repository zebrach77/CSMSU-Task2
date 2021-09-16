#include <stdio.h>
#define RESET   "\033[0m"
#define RED     "\033[31m"
typedef char myStr;
int char2intDigit(char c)
{
  return c-'0';
}


double str2double(myStr str[])
{
  int ind1;
  double res = 0, temp=1;
  ind1 = 0;
  //integer part
  while (str[ind1] != '.')
  {
    res = (res * 10.0) + char2intDigit(str[ind1]);
    ++ind1;
  }
  ++ind1;
  //double part
  fprintf(stderr, RED "%u\n" RESET, sizeof str / sizeof *str);
  for (int i = ind1; i< 1000; ++i)
  {
    if (!str[i])
      break;
    temp = temp / 10.0;
    res += char2intDigit(str[i])*temp;
  }
  return res;
}


int main()
{
  myStr temp[2000];
  while(scanf("%s", &temp)!=EOF)
  {
    printf("%lf\n", str2double(temp));
  }
}
