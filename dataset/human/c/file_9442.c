#include <stdio.h>

int main(void) {
  int N, D, X;
  int A[110];
  int i;
  int sum = 0;
  
  scanf("%d %d %d", &N, &D, &X);
  for(int i = 0; i < N; i++) {
    int A;
    scanf("%d", &A);
    sum += (D-1)/A + 1;
  }
  printf("%d\n", X + sum);
  
  return 0;
}
