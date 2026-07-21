#include <stdio.h>
#define LL long long

int gcd(LL int a, LL int b)
{
  if(b == 0)
    return a;
  else
    return gcd(b,a%b);
}

int main()
{
  LL int A,B;
  scanf("%lld %lld",&A,&B);
  printf("%lld",A*B/gcd(A,B) );

  return 0;
}
