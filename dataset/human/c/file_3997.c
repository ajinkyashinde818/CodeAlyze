#include <stdio.h>
#include <string.h>
int main(void){

  int A=0,B=0,K=0,n=0;
  int num[100]={0};
  scanf("%d%d%d",&A,&B,&K);
  
  for(int i=1;i<=100;i++){
  	if(A%i == 0 && B%i == 0){
    	num[n]=i;
      	n++;
    }
  }
  
  printf("%d",num[n-K]);
  
  
 return 0;
}
