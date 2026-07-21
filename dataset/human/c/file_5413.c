#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
  long N, M, X, C[20], A[20][20], i, j, k, num = 1, c, a[20], ans = -1;
  scanf("%ld %ld %ld", &N, &M, &X);
  for (i = 0; i < N; i++) {
    scanf("%ld", C + i);
    for (j = 0; j < M; j++) {
      scanf("%ld", A[i] + j);
    }
  }
  for (i = 0; i < N; i++) num *= 2;
  for (i = 1; i < num; i++) {
    c = 0;
    for (j = 0; j < M; j++) a[j] = 0;

    for (j = 0; j < N; j++) {
      if (i & (1 << j)) {
        c += C[j];
        for (k = 0; k < M; k++) a[k] += A[j][k];
      }
    }
    for (j = 0; j < M; j++) if (a[j] < X) break;
    if (j == M) {
      if (ans == -1 || ans > c) ans = c;
    }
  }
  printf("%ld", ans);
  return 0;
}
