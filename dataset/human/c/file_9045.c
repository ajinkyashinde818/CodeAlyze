#include <stdio.h>
int main(void) {
  int N, K, h[1000000], i, x;
  scanf("%d", &N);
  scanf("%d", &K);
  for (i = 0; i < N; i++) {
    scanf("%d", &h[i]);
  }
  for (i = 0; i < N; i++) {
    if (h[i] >= K) x++;
  }
  printf("%d\n", x);
  return 0;
}
