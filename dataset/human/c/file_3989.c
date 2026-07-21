#include <stdio.h>

int max(int a,int b){
  if(a > b){
    return a;
  }
  return b;
}

int main(void){
  int A,B,K;
  scanf("%d%d%d",&A,&B,&K);

  for(int i = max(A,B);i > 0;i--){
    if(A%i == 0 && B%i == 0) K--;
    if(K == 0){
      printf("%d\n",i);
      break;
    }
  }
  
   

  return 0;
}
