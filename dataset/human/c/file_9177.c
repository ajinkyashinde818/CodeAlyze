#include <stdio.h>

int main(void)
{
  int N, K;
  int i;
  int count = 0;

  scanf("%d %d",&N,&K);

  for(i=0;i<N;i++){
    int a;
    scanf("%d",&a);
    if(a>=K)count++;
  }
  printf("%d",count);

  return 0;
}
