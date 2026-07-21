#include <stdio.h>

int main()
{
  int a, b, k;
  int i, count = 0;

  scanf("%d%d%d", &a, &b, &k);

  for (i = (a < b ? a : b); count != k; i--) {
    if (a % i == 0 && b % i == 0) {
      count++;
    }
  }

  printf("%d\n", i + 1);

  return 0;
}
