#include <stdio.h>
#include <time.h>




long long fibRecursive(long long f1, long long f2, int n)
{
  if (n>0)
    return fibRecursive(f2, f1+f2, n-1);
  else
    return f1;
}


long long fibIterative(int n)
{
  long long f1 = 0;
  long long f2 = 1;
  long long temp;
  for (int i = 0; i < n; ++i)
  {
    temp = f1+f2;
    f1 = f2;
    f2 = temp;
  }
  return f1;
}



int main(){
  clock_t start, end;
  double cpu_time_used1, cpu_time_used2;
  long long ans1, ans2;
  int n;
  scanf("%d", &n);
  start = clock();
  ans1 = fibRecursive(0, 1, n);
  end = clock();
  cpu_time_used1 = ((double) end - start) / CLOCKS_PER_SEC;
  printf("Recursive function answer: %lld, time: %fd\n", ans1, cpu_time_used1);


  start = clock();
  ans2 = fibIterative(n);
  end = clock();
  cpu_time_used2 = ((double) end - start) / CLOCKS_PER_SEC;
  printf("Iterative function answer: %lld, time: %fd\n", ans2, cpu_time_used2);
}
