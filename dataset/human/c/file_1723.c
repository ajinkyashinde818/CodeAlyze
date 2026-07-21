#include <stdio.h>

int main(void){
  int N;
  int A[25];
  int B[25];
  int C[25];
  int i;

  scanf("%d", &N);

  for (i = 1; i <= N; i++) {
    scanf("%d", &A[i]);
  }

  for (i = 1; i <= N; i++) {
    scanf("%d", &B[i]);
  }
  for (i = 1; i <= N-1; i++) {
    scanf("%d", &C[i]);
  }

  int ans = 0;

  for (i = 1; i <= N; i++) {
    ans += B[i];
  }

  for (i = 1; i <= N-1; i++) {
    if (A[i+1] == A[i] + 1) {
      ans += C[A[i]];
    }
  }

  printf("%d\n", ans);

}
