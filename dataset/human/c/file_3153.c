#include <stdio.h>

int main(){
  int K, N ;
  int A[200001];
  int min;
  
  scanf("%d %d",&K , &N);

  for(int i=1;i<=N;i++)
    scanf("%d", &A[i]);

  A[0] = A[N] - K;

  min = K;
  for(int i=1;i<=N;i++)
    if( min > K - A[i]+A[i-1] )
      min = K - A[i] + A[i-1] ;

  printf("%d\n",min);

  return 0;
}
