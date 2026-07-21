#include <stdio.h>

int max(int a, int b)
{
  return a > b ? a : b;
}

int min(int a, int b)
{
  return a < b ? a : b;
}


int main()
{
  int i;
  int n, r;
  int maxv = -1000000000, minv;

  scanf("%d", &n);
  scanf("%d", &r);
  minv = r;

  for (i = 1; i < n; i++) {
    scanf("%d", &r);
    maxv = max(maxv, r - minv);
    minv = min(minv, r);
  }

  printf("%d\n", maxv);

  return 0;
}
