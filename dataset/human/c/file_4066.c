#include <stdio.h>
int main(void){
  int A,B,K,i,j=1,x[100];
  scanf("%d",&A);
  scanf("%d",&B);
  scanf("%d",&K);
  for(i=100;i>0;i--){
    if(A%i==0){
      if(B%i==0){
        x[j]=i;
        j=j+1;}
      else{}
    }
    else{}
  }
  printf("%d",x[K]);
  return 0;
}
