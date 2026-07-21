#include <stdio.h>

int main(void)
{
  int r, g, b, n = 0;
  int ans, tmp = 0;
  scanf("%d", &r);
  scanf("%d", &g);
  scanf("%d", &b);
  scanf("%d", &n);
  for (int i = 0; i <= n / r; i++)
  {
    int ri = r * i;
    if (ri > n)
    {
      break;
    }
    for (int j = 0; j <= n / g; j++)
    {
      tmp = ri + g * j;
      if (tmp > n)
      {
        break;
      }
      else if ((n - tmp) % b == 0)
      {
        ans++;
      }
    }
  }

  printf("%d", ans);
  return 0;
}
