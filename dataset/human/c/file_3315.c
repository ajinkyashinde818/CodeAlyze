#include <stdio.h>
#include <stdlib.h>
int main(){
  int K, N, m = 0;
  int *A, *D;
  scanf("%d %d", &K, &N);
  A = (int *)malloc(sizeof(int) * N);
  D = (int *)malloc(sizeof(int) * (N+1));
  for(int i=0; i<N; i++){
    scanf("%d ", &A[i]);
    if(i > 0 && m < A[i] - A[i-1]) m = A[i] - A[i-1];
  }
  if(m < A[0] + K - A[N-1]) m = A[0] + K - A[N-1];
  
  printf("%d\n", K - m);
  
  free(A);
  free(D);
}
