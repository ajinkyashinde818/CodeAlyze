#include<stdio.h>

int main(){
  int A,B,K,max;
  int i,count=0;

  scanf("%d %d %d", &A,&B,&K);

  if(A>=B){
    max=A;
  }else{
    max=B;
  }

  for(i=max;i>=1;i--){
    if(A%i==0){
      if(B%i==0){
        count++;
        if(count==K){
          break;
        }
      }
    }
  }

  printf("%d\n", i);

  return 0;
}
