#include <stdio.h>
 
int main(void) {
  
  int N,A[20],B[20],C[20];
  
  //標準入力
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  for (int i = 0; i < N; i++) {
    scanf("%d", &B[i]);
  }
  for (int i = 0; i < N - 1; i++) {
    scanf("%d", &C[i]);
  }
  
  //満足度の合計
  int sum = 0;
  for (int i = 0; i < N; i++) {
    sum += B[A[i] - 1];
    if (A[i+1] - A[i] == 1) {
      sum += C[A[i] -1];
    }
  }
  
  //出力
  printf("%d", sum);
  
  return 0;
}
