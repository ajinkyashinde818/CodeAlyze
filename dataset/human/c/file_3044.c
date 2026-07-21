#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



int main() {
  long i, N, K, A[200005], s = 0;
  scanf("%ld %ld", &K, &N);
  scanf("%ld", A);
  for (i = 1; i < N; i++) {
    scanf("%ld", A + i);
    if (A[i] - A[i - 1] > s) {
      s = A[i] - A[i - 1];
    }
  }
  if (A[0] - A[N - 1] + K > s) {
    s = A[0] - A[N - 1] + K;
  }
  printf("%ld", K - s);
  return 0;
}
