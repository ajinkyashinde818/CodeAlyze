#include <stdio.h>

int main(void) {
  int N, D, X, cnt = 0;
  (void)scanf("%d %d %d", &N, &D, &X);

  for (int i = 0; i < N; i++) {
    int A;
    (void)scanf("%d", &A);
    cnt += (D-1) / A + 1;
  }
  printf("%d\n", cnt + X);

  return 0;
}
