#include<stdio.h>
 
int main(void){
  int A,B;
  if(scanf("%x %x",&A,&B) == 1);
  if(A >=10 && B >=10 && A <= 15 && B <= 15){
    if (A>B)
      printf(">");
    else if (A<B)
      printf("<");
    else
      printf("=");
  }
  return 0;
}
