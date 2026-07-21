#include<stdio.h>
int main(void)
{
  int N,K,h[100000];
  int a=0;
  scanf("%d%d",&N,&K);
  for (int i=0;i<N;i++) {
    scanf("%d",&h[i]);
    if (h[i]>=K){
      a=a+1;
    }
  }
  printf("%d",a);
  return 0;
}
