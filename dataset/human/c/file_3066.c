/* C - Traveling Salesman around Lake */

#include <stdio.h>

int main(void){
  int K, N, i, A[200000], max;
  scanf("%d %d", &K, &N);
  for(i = 0; i < N; i++){
    scanf("%d", &A[i]);
    if(i == 0){
      max = A[i];
    }
    if(i > 0){
      if(A[i] - A[i - 1] > max){
        max = A[i] - A[i - 1];
      }
      if(i == N - 1){
        if(A[0] + (K - A[i]) > max){
          max = A[0] + (K - A[i]);
        }
      }
    }
  }
  printf("%d\n", K - max);
}
