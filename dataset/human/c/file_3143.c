#include <stdio.h>

int main()
{
  int k,n;
  scanf("%d%d",&k,&n);
  int i;
  i = 0;
  int max;
  max = 0;
  int a[n];
  while (i < n)
  {
    scanf("%d", &a[i]);
    if (i > 0 && max < a[i] - a[i - 1])
    {
      max = a[i] - a[i - 1];
    }
    i++;
  }
  if (max < a[0] + k - a[n - 1])
  {
    max = a[0] + k - a[n - 1];
  }
  printf("%d",k-max);
}
