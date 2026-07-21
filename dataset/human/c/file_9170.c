#include <stdio.h>

int main(){
  int N;
  int K;
  int h[100000];
  int count=0;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
      scanf("%d",&h[i]);
  }
  for(int i=0;i<N;i++){
    if(h[i]>=K){
      count++;
    }
  }
  printf("%d",count);

	return 0;
}
