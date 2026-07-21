#include<stdio.h>

int main(void){
  
  int A,B,K;
  int result,k_th = 0;
  
  scanf("%d %d %d",&A,&B,&K);
  
  if(A > B){
    result = A;
  }else{
    result = B;
  }
  
  while(k_th != K){
    if(A % result == 0 && B % result == 0){
     k_th++; 
    }
    if(k_th != K){
     result--; 
    }
  }
  
  printf("%d",result);
  return 0;
}
