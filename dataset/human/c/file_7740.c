#include<stdio.h>
#define NUMBER 100
int main(void)
{
  int N,K,P;
  int i;
  int A[NUMBER];

  scanf("%d",&N);
  for( i = 0; i < N; i++){
    scanf("%d %d",&K,&P);
    A[i] = K % P;
    if(K % P == 0)
      A[i] = P;
  }

  for( i = 0; i < N; i++){
    printf("%d\n",A[i]);
  }
  
  return 0;
}
