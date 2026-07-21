#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  int N, M;
  scanf("%d %d", &N, &M);

  int from1[200000];
  int dst1 = 0;
  bool toN[200001];
  memset(toN, 0, N);
  for (int i = 0; i < M; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a == 1) {
      from1[dst1++] = b;
    }
    if (b == N) {
      toN[a] = true;
    }
  }

  for (int i = 0; i < dst1; i++) {
    int v = from1[i];
    if (toN[v]) {
      printf("POSSIBLE\n");
      return 0;
    }
  }
  printf("IMPOSSIBLE\n");
  return 0;
}
