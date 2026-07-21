#include<stdio.h>
int main(void){
  long long int a,b,x,r,tmp;
  scanf("%lld%lld",&a,&b);
  x=a*b;
  if(a<b){
    tmp = a;
    a = b;
    b = tmp;
  }
  r = a % b;
  while(r!=0){
    a = b;
    b = r;
    r = a % b;
  }
  printf("%lld\n",x/b);
  return 0;
}
