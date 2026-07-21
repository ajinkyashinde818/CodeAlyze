#include<stdio.h>

int main(){
  
  int K, S, Sum = 0;
  scanf("%d%d",&K,&S);
  
  for(int i=0; i<=K; i++){
    for(int j=0; j<=K; j++){
      if(S-i-j<=K && S-i-j >= 0) Sum++;
    }
  }
  printf("%d\n", Sum);
  return 0;
}
