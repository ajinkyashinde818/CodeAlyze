#include <stdio.h>
int main() {
  int N, i, recently, ans;
  recently = 0;
  ans = 0;
  scanf("%d", &N);
  int A[N + 1];
  int B[N + 1];
  int C[N];
  for (i = 1; i < N + 1; ++i) {
    scanf("%d", &A[i]);
  }
  for (i = 1; i < N + 1; ++i) {
    scanf("%d", &B[i]);
  }
  for (i = 1; i < N; ++i) {
    scanf("%d", &C[i]);
  }
  ans += B[A[1]];
  recently = A[1];
  for (i = 2; i < N + 1; ++i) {
    ans += B[A[i]];
    if (recently == A[i] - 1) {
      ans += C[A[i]-1];
    }
    recently = A[i];
  }
  printf("%d\n", ans);
  return 0;
}
