#include<stdio.h>
int main(){
  long long a,b,c,d,e;
  scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&e);
  a-=d*100/b+e*100/c;
  if(d*100%b)a--;
  if(e*100%c)a--;
  //prrintf("%lld %lld",c*100/);
  printf("%lld\n",a<0?-1:a);
  return 0;
}
