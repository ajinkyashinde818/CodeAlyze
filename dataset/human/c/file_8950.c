#include<stdio.h>

int main(void){
  int count,num,sub;
  while(1){
    count=0;
    scanf("%d",&num);
    if(num==0){
      break;
    }else{
      while(num!=1){
	if(num%2==0){
	  num/=2;
	}else{
	  sub=3*num+1;
	  num=sub;
	}
	//printf("%d\n",num);
	count++;
      }
    }
    printf("%d\n",count);
  }
  return 0;
}
