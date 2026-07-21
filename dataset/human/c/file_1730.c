#include <stdio.h>

int main(){
  int N,S=0;
  int A[30],B[30],C[30];
  scanf("%d",&N);
  for(int i=1;i<=N;i++)
    scanf("%d",A+i);
  for(int i=1;i<=N;i++)
    scanf("%d",B+i);
  for(int i=1;i<=N;i++)
    scanf("%d",C+i);
  for(int i=1;i<=N;i++)
    S+=B[A[i]];
  for(int i=1;i<N;i++)
    if(A[i]+1==A[i+1])
      S+=C[A[i]];
  printf("%d\n",S);
  return 0;
}
