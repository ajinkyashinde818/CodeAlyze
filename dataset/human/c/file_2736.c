#include<stdio.h>
int main(){
  int K,S;
  scanf("%d%d",&K,&S);
  int i,j;
  int count=0;
  for(i=0;i<=K;i++){
    for(j=0;j<=K;j++){
        if(S-i-j<=K&&S-i-j>=0){
          count++;
      }
    }
  }
  printf("%d",count);
}
