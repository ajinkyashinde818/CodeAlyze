#include <stdio.h>

int main() {
  int N, ans = 0;
  scanf("%d", &N);
  int A[N+1], B[N+1], C[N+1];
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &A[i]);
  }
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &B[i]);
  }
  for (int i = 1; i <= N-1; ++i) {
    scanf("%d", &C[i]);
  }
  for (int i = 1; i <= N; ++i) {
    ans += B[A[i]];
    if (i <= N-1 && A[i]+1 == A[i+1]) ans += C[A[i]];
  }
  printf("%d\n", ans);
  return 0;
}
