#include<stdio.h>
int main(){
  int N,K,i,total=0;
  int hei[100000];
  scanf("%d %d",&N,&K);
  for(i=0;i<N;i++){
    scanf("%d",&hei[i]);
  }
  for(i=0;i<N;i++){
    if(hei[i] >= K){
      total++;
    }
  }
  printf("%d\n",total);
  return 0;
}
