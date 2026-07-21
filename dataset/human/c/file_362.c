#include <stdio.h>
#include <stdlib.h>

int main(void){
  int n,r,x;
  scanf("%d",&n);
  scanf("%d",&r);
  if(n>=10){
    printf("%d",r);
  }else{
    x=r+(100*(10-n));
    printf("%d",x);
  }
  return 0;
}
