#include<stdio.h>

int main(){
  int N,K,i;
  scanf("%d",&N);
  char S[N];
  scanf("%s",S);
  scanf("%d",&K);
  
  for(i=0;i<N;i++){
    if(S[K-1]==S[i])
      printf("%c",S[i]);
    else
      printf("*");
  }
  puts("");
  return 0;
}
