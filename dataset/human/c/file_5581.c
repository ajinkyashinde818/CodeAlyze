#include<stdio.h>
int main(void)
{
  int n,i;

  scanf("%d%d",&n,&i);
  if(1>n){
    return 1;
  }else if(n>100){
    return 1;
  }else if(1>i){
    return 1;
  }else if(i>n){
    return 1;
  }

  printf("%d\n",n-i+1);
  return 0;
}
