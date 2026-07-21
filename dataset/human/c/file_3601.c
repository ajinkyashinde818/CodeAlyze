#include <stdio.h>
long long gcd(long long x,long long y);
int main()
{
    long long n,t,c;
    scanf("%lld %lld",&n,&t);
    c=n/gcd(n,t)*t;
    printf("%lld",c);
}
long long gcd(long long x,long long y)
{
    return x?gcd(y%x,x):y;
}
