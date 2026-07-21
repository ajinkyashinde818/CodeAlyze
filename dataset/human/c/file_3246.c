#include <stdio.h>

int main(void)
{
  int k, n;
  scanf("%d %d", &k, &n);
  int a[n], i;
  i = 0;
  while (i < n)
  {
    scanf("%d", &a[i]);
    i++;
  }
  
  i = 0;
  int min = k;
  int dis_i = 0;
  while (i < n)
  {
    if (i >= 1 && i + 1 < n)
    {
      // left
      dis_i = 0;
      dis_i = k - (a[i] - a[i - 1]);
      if (min > dis_i)
      {
        min = dis_i;
      }
      // right
      dis_i = 0;
      dis_i = k - (a[i + 1] - a[i]);
      if (min > dis_i)
      {
        min = dis_i;
      }
    }
    else if (i == 0)
    {
      // left
      dis_i = 0;
      dis_i = k - (a[i + 1] - a[i]);
      if (min > dis_i)
      {
        min = dis_i;
      }
      // right
      dis_i = 0;
      dis_i = a[n - 1] - a[i];
      if (min > dis_i)
      {
        min = dis_i;
      }
    }
    else if (i == n - 1)
    {
      // left
      dis_i = 0;
      dis_i = a[i] - a[0];
      if (min > dis_i)
      {
        min = dis_i;
      }
      // right
      dis_i = 0;
      dis_i = (k - a[i]) + a[i - 1];
      if (min > dis_i)
      {
        min = dis_i;
      }
    }
    i++;
  }
  printf("%d", min);
  return 0;
}
