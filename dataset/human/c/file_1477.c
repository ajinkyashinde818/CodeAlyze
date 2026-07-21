#include<stdio.h>
#include<stdlib.h>

int main(){
  int num,i,a;
  a=scanf("%d",&num);

  if(90<=num && num<100){
    printf("Yes\n");
    return 0;
  }
  
  for(i=90;i>=0;i=i-10){
    if((num-i)==9){
      printf("Yes\n");
    return 0;
    }
  }

  printf("No\n");

}
