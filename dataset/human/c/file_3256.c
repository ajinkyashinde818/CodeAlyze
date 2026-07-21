#include <stdio.h>
 
int main(void) {
  
  int K, N, i;
  int max=0;
  int kyori;
  
  scanf("%d",&K);
  scanf("%d",&N);
  
  int A[N];
  int B[N];
  
  for(i=0; i<N; i++){
    scanf("%d", &A[i]);
  }
  
  for(i=0; i<N-1; i++){
    B[i] = A[i+1] - A[i];
  }
  
  B[N-1] = A[0] - A[N-1] + K;
  
  for(i=0;i<N;i++){
    if(max<B[i])
      max=B[i];
  }
  
  kyori = K - max;
  
  printf("%d\n", kyori);
  
  return 0;
}
