#include <stdio.h>

int main(void){
  int K,S;
  scanf("%d%d",&K,&S);
  int counter = 0;
  int i,j;
  for(i=0;i<=K;i++){
    for(j=0;j<=K;j++){
      if(S-i-j >= 0 && S-i-j <= K){
        counter ++;
      }
    }
  }
  printf("%d\n",counter);

}
