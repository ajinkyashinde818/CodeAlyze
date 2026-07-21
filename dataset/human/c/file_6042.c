#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int d, max = -999999999, n, t;
  scanf("%d", &n);
  for(t = 0; t < n; t++)
  {
    int R;
    scanf("%d", &R);
    if(t == 0)
    {
      d = R;
    }
    if(t == 1)
    {
      max = R - d;
    }
    if(R < d)
    {
      if(max < R - d)
      {
        max = R - d;
      }
      d = R;
    }
    else
    {
      if(R - d > max)
      {
        max = R - d;
      }
    }
  }
  printf("%d\n", max);
  return 0;
}
