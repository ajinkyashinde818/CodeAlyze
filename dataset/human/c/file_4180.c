#include<stdio.h>
int main(void){
  int A,B,K,count=0,i; scanf("%d%d%d",&A,&B,&K);
  for(i=(A>=B)?A:B;i>0;i--){
    if(A%i==0&&B%i==0){
      count++;
      if(count>=K){
        break;
      }
    }
  }
  printf("%d\n",i);
  return 0;
}
