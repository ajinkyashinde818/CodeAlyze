#include <stdio.h>

int main(){
  int N,i,ct=0;

  scanf("%d",&N);
  int A[N];
  int B[N];
  int C[N-1];

  for(i=0;i<N;i++)scanf("%d",&A[i]);
  for(i=0;i<N;i++)scanf("%d",&B[i]);
  for(i=0;i<N-1;i++)scanf("%d",&C[i]);

  for(i=0;i<N;i++)ct+=B[A[i]-1];
  for(i=0;i<N-1;i++)if(A[i+1]-A[i]==1)ct+=C[A[i]-1];

  printf("%d\n",ct);

  return 0;
}
