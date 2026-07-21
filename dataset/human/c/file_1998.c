#include<stdio.h>
#include<math.h>

long long int min(long long int a,long long int b){
  if(a>b) return b;
  return a;
}

int main(void){
  long long int a,b,c,tmp;
  scanf("%lld %lld %lld",&a,&b,&c);
  tmp = min(a+b,c);
  if((a+b)<c) tmp++;
  printf("%lld\n",tmp+b);
  return 0;
}
