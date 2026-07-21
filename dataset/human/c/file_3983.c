#include<stdio.h>

int main(){
  int i,j,k=0;
  int A,B,C;
  int K[1000];
  scanf("%d %d %d",&A,&B,&C);
  if(A<B){
    for(i=1;i<=A;i++){
      if(A%i==0&&B%i==0){
        K[k]=i;
        k++;
      }
    }
  }
  
  else{
    for(i=1;i<=B;i++){
      if(A%i==0&&B%i==0){
        K[k]=i;
        k++;
      }
    }
  }
  
  printf("%d\n",K[k-C]);
  return 0;
  
}
