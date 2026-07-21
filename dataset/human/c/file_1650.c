#include<stdio.h>
int main()
{
  /*
  	N
    A1, A2, ..., An
    B1, B2, ..., Bn
    C1, C2, ..., Cn-1
    
  */
  
  int A[25]={};
  int B[25]={};
  int C[25]={};
  int N;
  
  scanf("%d",&N);
  int i;
  int point=0;
  
  for(i=0;i<N;i++)
  	scanf("%d",&A[i]);
  for(i=0;i<N;i++)
    scanf("%d", &B[i]);
  for(i=0;i<N-1;i++)
    scanf("%d",&C[i]);
  
  for(i=0;i<N;i++)
  {
    point+=B[A[i]-1];
    if(i>=1&&A[i]==A[i-1]+1)
      point+=C[A[i-1]-1];
  }
  printf("%d",point);
  return 0;
}
