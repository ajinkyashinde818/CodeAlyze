#include <stdio.h>

int main(void)
{
  int K, N;
  scanf("%d %d", &K, &N);
  
  int A[N];
  int i;
  for(i=0; i<N; i++){
    scanf("%d", &A[i]);
  }
  
  int mx = 0;
  for(i=0; i<N-1; i++){
    if(mx < A[i+1] - A[i])
      mx = A[i+1] - A[i];
  }
  if(mx < A[0] + K - A[N-1])
    mx = A[0] + K - A[N-1];
  
  printf("%d", K - mx);
  
  return 0;
}
