#include<stdio.h>
int main(void){
	int a,b,c,k,i;
  	int count;
  	count = 0;
  	scanf("%d",&a);
  	scanf("%d",&b);
    scanf("%d",&k);
  if (a > b){
    c = a;
  }else{
    c = b;
  }
  for(i = 100; i >= 1 ; i--){
    if (a%i == 0 && b%i == 0){
      count = count + 1;
      if (count == k){
        printf("%d",i);
        break;
      }
    }
   }
}
