#include <stdio.h>

int main(void){
  long long a,b,r,tmp,x;
  scanf("%lld %lld",&a,&b);
  x=a*b;
  if(a>b){
    tmp=a;
    a=b;
    b=tmp;
  }
  r=b%a;
  while(r!=0){
    b=a;
    a=r;
    r=b%a;
  }
  printf("%lld\n",x/a);
  return 0;
}
