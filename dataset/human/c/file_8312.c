#include<stdio.h>
int main(void){
  int S,K,i;
  char r[15]={'\0'};
  scanf("%d",&S);
  scanf("%s",r);
  scanf("%d",&K);
  for(i=0;i<S;i++){
    if(r[i]!=r[K-1]){
      r[i]='*';
    }
  }
  printf("%s",r);
  return 0;
}
