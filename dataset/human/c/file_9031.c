#include<stdio.h>
int main(){
  int N,K,ok;
  scanf("%d%d",&N,&K);
  int h[N];
  ok=0;
  for(int i=0;i<N;i++){
    scanf("%d",&h[i]);
    if(h[i]>=K)
      ok++;
  }
  printf("%d\n",ok);
  return 0;
}
