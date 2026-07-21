#include <stdio.h>
int main(void){
  int A,B,K;
  int i=1,j=1;
  int C[100];
  scanf("%d %d %d",&A,&B,&K);
  
  for(i=1;i<=A && i<=B;i++){
      if((A%i==0) &&(B%i==0)){
      C[j]=i;
      j++;
      }
  }
  printf("%d",C[j-K]);
  
  return(0);
}
