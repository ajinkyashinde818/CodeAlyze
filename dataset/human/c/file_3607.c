#include <stdio.h>
#include <stdlib.h>
long long int gcd(long long int x,long long int y)
{ if(!y)return x;
  return gcd(y,x%y);

}
int main()
{   long long int a,b;
scanf("%lld %lld",&a,&b);
printf("%lld",a*b/gcd(a,b));

    return 0;
}
