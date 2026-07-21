#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long gcd(long long x,long long y)
{
    return y?gcd(y,x%y):x;
}

int main()
{
    long long a,b;
    scanf("%lld%lld",&a,&b);
    long long c=gcd(a,b);
    long long d=a*b/c;
    printf("%lld",d);
}
