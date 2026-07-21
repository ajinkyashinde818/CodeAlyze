//abc145D
#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long gya(long long a) { //逆元を求める
  long long m=1000000007, b=m, u=1, v=0, c, t;
  while(b){
    t=a / b; //何これ
    a-=t * b, u-=t * v; //何これ
    c=a, a=b, b=c, c=u, u=v, v=c; //swap
  }
  return (u + m) % m;
}
long long com(long long b, long long d) { //bCd
  int i, mod=1000000007;
  long long ret=1, re2=1;
  for(i=1; i <= d; i++)
    ret=ret * (b - d + i) % mod, re2=re2 * i % mod;
  return ret * gya(re2 % mod) % mod;
}

int main(void) {
  int x, y, tmp, n, m;
  scanf("%d %d", &x, &y);
  if((x + y) % 3 != 0 || x / y > 2 || y / x > 2){
    printf("0");
    return 0;
  }else if(y > x) tmp=x, x=y, y=tmp;

  n=(2 * y - x) / 3, m=(x + y) / 3 - n;
  //printf("%d %d\n",n,m);
  printf("%lld", com(n+m, m));
  return 0;
}
