#include <stdio.h>

int main(){
long A,B;
  long small,big;
long LCM;
  int i;
  
  scanf("%ld %ld",&A,&B);
  if(A<B){
    small = A;
    big  = B;
  }else{
    small = B;
       big = A;
  }
  
 for(i = 1;i  <= big;i++){
    LCM = small * i;
    if(LCM%big == 0) break;
  }
  
  printf("%ld\n",LCM);
  return 0;
}
