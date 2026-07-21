#include <stdio.h>
int main(void){
  int K,S,cnt = 0;
  scanf("%d %d",&K,&S);
  for(int i = 0;i <= K;i++){
    for(int j = 0;j <= K;j++){
      if(0 <= S - i - j && S - i - j <= K){
        cnt++;
      }
    }
  }
  printf("%d",cnt);
  return 0;
}
