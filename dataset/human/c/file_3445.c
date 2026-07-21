#include<stdio.h>
int main(void)
{
  int N,i,j,x,A[200000]={0},check[200000]={0},move[200000]={0};
  long long K;
  i=scanf("%d %lld",&N,&K);
  for(i=0;i<N;i++)check[i]=-scanf("%d",&A[i]);
  for(i=0,j=0;;i=A[i]-1,j++)if(check[i]<0)check[i]=j,move[j]=i;else{x=check[i];break;}
  if(K>=j)K=(K-x)%(x-j)+x;
  return printf("%d\n",move[K]+1),0;
}
