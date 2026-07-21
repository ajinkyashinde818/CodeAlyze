#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
  return (a > b ? a : b);
}

int main(void) {
  int N;
  int R;

  scanf("%d %d", &N, &R);

  printf("%d\n", R + max(0, 100 * (10 - N)));

  return (0);
}
