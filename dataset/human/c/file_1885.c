#include <stdio.h>
int main () {
  int N;
  int A[30];
  int B[30];
  int C[30];
  int i;
  int n;
  int ans = 0;
  scanf ("%d", &N);

  for (i = 0; i < N; i++) {
    scanf ("%d", &A[i]);
  }

  for (i = 0; i < N; i++) {
    scanf ("%d", &B[i]);
  }

  for (i = 0; i < N - 1; i++) {
    scanf ("%d", &C[i]);
  }
  for (i = 0; i < N; i++) {
    n = A[i];
    ans += B[n - 1];

    if (A [i + 1] - A[i] == 1) {
      ans += C[n - 1];
    }
  }

  printf ("%d", ans);


  return 0;
}
