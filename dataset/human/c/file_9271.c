#include<stdio.h>

int main(void){
  int N,K;
  scanf("%d%d",&N,&K);
  int P[N];
  int count = 0;
  for(int i = 0;i < N;i++)
    scanf("%d",&P[i]);
  for(int i = 0;i < N;i++){
    if(P[i] >= K)
      count++;
  }
  printf("%d",count);
  return 0;
}
