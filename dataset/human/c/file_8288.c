#include<stdio.h>
int main(){
  int i,N,K;
  char S[11],a;
  scanf("%d",&N);
  scanf("%s",&S);
  scanf("%d",&K);
  for(i=0;i<N;i++){
    a=S[K-1];
    if(S[i]!=a){
      S[i]='*';
    }
  }
    printf("%s",S);
  return 0;
}
