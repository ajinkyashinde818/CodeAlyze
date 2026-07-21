#include <stdio.h>
#define SIZE 10000

int main() {
  int x[SIZE], i, j;

  i = 0;
  while (i++ <= SIZE) {
    scanf("%d", &x[i]);
    if (x[i] == 0)
      break;
  }
  for (j = 1; j < i; j++)
    printf("Case %d: %d\n", j, x[j]);

  return 0;
}
