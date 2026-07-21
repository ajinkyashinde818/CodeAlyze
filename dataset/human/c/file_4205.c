#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SUM 1000000007

long calcFib(int n)
{
  if(n == 0) return (long long)1;
  else if(n == 1) return (long long)1;

  long long a2, a1 = 1, a0 = 1;
  for(int i = 1; i < n; i++)
  {
    a2 = (a1 + a0) % SUM;
    a0 = a1;
    a1 = a2;
  }
  return a2;
}

int main(void)
{
  int *a;
  int n, m;
  scanf("%d %d", &n, &m);
  a = (int*)malloc((n - 1) * sizeof(int));
  for(int i = 1; i <= m; i++)
  {
    scanf("%d", a + i);
  }

  long long all = 1;
  a[0] = -1;
  for(int i = 1; i <= m; i++)
  {
    all = (all * calcFib(a[i] - a[i - 1] - 2)) % SUM;
  }
  all = (all * calcFib(n - a[m] - 1)) % SUM;

  printf("%ld\n", all);

  return 0;
}
