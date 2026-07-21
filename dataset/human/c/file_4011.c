#include<stdio.h>
int main(void)
{
  int A,B,K,cnt=0;
  scanf("%d%d%d",&A,&B,&K);
  
  if(A>B){
    for(int i=A;i>=1;i--){
      if((A%i==0) && (B%i==0)){
        cnt++;
        if(cnt==K){
          printf("%d",i);
        }
      }
    }
  }else{
    for(int i=B;i>=1;i--){
      if((A%i==0) && (B%i==0)){
        cnt++;
        if(cnt==K){
          printf("%d",i);
        }
      }
  	}   
  }
  
  return 0;
}
