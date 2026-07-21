#include<stdio.h>
int main(void){
  int number;
  int count=0;
  while(scanf("%d",&number)){
    if(number==0){
      break;
    }
    while(number!=1){
      if(number%2==0){
	number=number/2;
	count++;
      }
      else{
	number=number*3+1;
	count++;
      }
    }
    printf("%d\n",count);
    count=0;
  }
  return 0;
}
