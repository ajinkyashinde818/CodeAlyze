#include<stdio.h>
int main(void){
  int a,b,c,d;
  scanf("%d %d %d %d",&a,&b,&c,&d);
  int mul_ab,mul_cd;
  mul_ab=a*b;
  mul_cd=c*d;
  int max=0;
  if(mul_ab<=mul_cd) max=mul_cd;
  if(mul_ab>=mul_cd) max=mul_ab;
  printf("%d",max);
  return 0;
}
