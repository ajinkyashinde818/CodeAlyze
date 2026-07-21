#include <stdio.h>
int main(void){
  int i, K, N, A[1000000], tmp;
  
  scanf("%d %d", &K, &N);
  for(i = 0; i < N; i++)
    scanf("%d", &A[i]);
  
  tmp = K - A[N-1] + A[0];
  for(i=1;i<N;i++)
  	if(tmp < (A[i] - A[i-1]))
      tmp = A[i] - A[i-1];
  
  printf("%d",K-tmp);
  
  return 0;
}
