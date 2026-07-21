#include<stdio.h>

int main() {
  int N, D, X, A[100], sum;
  scanf("%d", &N);
  scanf("%d", &D);
  scanf("%d", &X);
  sum = X;
  for (int i=0 ; i<N ; i++) {
    scanf("%d", &A[i]);
    for (int j=1 ; j<=D ; j = j+A[i]) {
      sum += 1;
    }
  }
  printf("%d\n", sum);
}
