#include <stdio.h>
int main() {
  int N, K, i, count;
  count = 0;
  scanf("%d", &N);
  scanf("%d", &K);
  int h[N+1];
  for (i = 0; i < N; ++i) {
    scanf("%d", &h[i]);
    if (h[i] >= K) {
      ++count;
    }
  }
  printf("%d\n", count);
  return 0;
}
