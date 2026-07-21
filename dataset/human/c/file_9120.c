#include<stdio.h>

int main(void){
  int N,K;
  
  scanf("%d%d",&N,&K);
  
  int h[N],count = 0;
  for(int i=0;i<N;i++){
    scanf("%d",&h[i]);
    if(h[i] >= K) count++;
  }
  
  printf("%d",count);
  
  return 0;
}
