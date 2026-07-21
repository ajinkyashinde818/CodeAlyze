#include<stdio.h>
#include<stdlib.h>
int main(void)
{
  int N,M,i,k,tmp;
  scanf("%d %d",&N,&M);
  int A[N];
  for(i=0;i<N;i++) scanf("%d",&A[i]);
  for(k=1;k<=M;k++)
  {
    for(i=0;i<N-1;i++)
    {
      if(A[i]%k>A[i+1]%k)
      {
        tmp=A[i];
        A[i]=A[i+1];
        A[i+1]=tmp;
      }
    }
  }
  for(i=0;i<N;i++) printf("%d\n",A[i]);
  return 0;
}
