#include <stdio.h>
int main(void)
{
  int n, d, x;
  scanf("%d%d %d", &n, &d, &x);
  int a[n];
  int i;
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  int sum = x;
  for (i = 0; i < n; i++)
    for (int k = 1; k <= d; k += a[i])
      sum++;
  printf("%d", sum);
  return 0;
}
