#include <stdio.h>
#include <stdlib.h>
/*ABC 140 B*/

int main(void)
{
  int N;
  int A[21] = {0};
  int B[21] = {0};
  int C[21] = {0};
  int sum   = 0;

  scanf("%d", &N);
  for (size_t i = 1; i <= N; i++) {
    scanf("%d", &A[i]);
  }
  for (size_t i = 1; i <= N; i++) {
    scanf("%d", &B[i]);
  }
  for (size_t i = 1; i <= N-1; i++) {
    scanf("%d", &C[i]);
  }

  for (size_t i = 1; i <= N; i++) {
    sum += B[ A[i] ];
    if (A[i] - A[i-1] == 1 && A[i] != 1) {
      sum += C[ A[i-1] ];
    }
  }

  printf("%d\n", sum);
  return 0;
}
