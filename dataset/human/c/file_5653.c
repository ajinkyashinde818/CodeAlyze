#include <stdio.h>
int main(){
  long x,tmp,result=0;
  
  scanf("%ld",&x);
  tmp=x;

  result+=(tmp/11)*2;
  tmp=tmp%11;
  
  if(7<=tmp){
    result+=2;
  } else if(1<=tmp && tmp<7) {
    result+=1;
  }
  
  printf("%ld",result);
}
