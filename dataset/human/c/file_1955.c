#include <stdio.h>

#define MAX 50

int main(void)
{
  int cont=0;
  int N;
  int A[MAX];
  int B[MAX];
  int C[MAX-1];
  int i;

  scanf("%d",&N);
  for(i=1;i<=N;i++)scanf("%d",&A[i]);
  for(i=1;i<=N;i++)scanf("%d",&B[i]);
  for(i=1;i<N;i++)scanf("%d",&C[i]);

  cont = B[A[N]];
  for(i=1;i<N;i++){
    cont += B[A[i]];
    if(A[i]+1==A[i+1])cont+=C[A[i]];
  }
  printf("%d\n",cont);


  return 0;
}
