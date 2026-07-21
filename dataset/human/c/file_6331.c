#include <stdio.h>

int main(void)
{
  int max = -1000000005, a[200000], small, tmp, n, i;
  scanf("%d", &n);
  scanf("%d", &a[0]);
  small = a[0];

  for (i = 1; i < n; i++)  {
    scanf("%d", &a[i]);
    if (a[i] - small > max)  {
      max = a[i] - small;
    }
    if (a[i] < small) {
      small = a[i];
    }
  }
  printf("%d\n", max);

  return 0;
}
