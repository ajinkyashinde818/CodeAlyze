#include <stdio.h>

int main(void){

  int N, K;
  scanf("%d %d",&N,&K);
  int h[N], i;
  for(i=0;i<N;i++){
    scanf("%d",&h[i]);
  }
  int j, count=0;
  for(j=0;j<N;j++){
    if(h[j]>=K){
      count+=1;
    }
  }
  printf("%d",count);
  return 0;
}
