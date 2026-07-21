#include<stdio.h>

int main(void)
{
  int N,K,i,A;
  int h[100000];
  A=0;
  scanf("%d %d",&N,&K);
  for(i=0;i<=N-1;i++){
    scanf("%d",&h[i]);
  }
  for(i=0;i<=N-1;i++){
    if(h[i]>=K){
      A++;
    }
  }
  printf("%d",A);
  
  return 0;
}
