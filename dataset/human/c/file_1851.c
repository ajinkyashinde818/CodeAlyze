#include <stdio.h>
int main () {
  int N;
  int A[21] = {0};
  int B[51] = {0};
  int C[51] = {0};
  int i;
  int n;
  int ans = 0;

  //入力
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

  //計算
  for (i = 0; i < N; i++) {
    n = A[i];
    ans += B[n - 1];

    if (A [i + 1] - A[i] == 1) {
      ans += C[n - 1];
    }
  }

  printf ("%d\n", ans);


  return 0;
}
