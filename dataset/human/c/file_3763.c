#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long int int64;

int64 gcd(int64 a,int64 b);

int main()
{
    int64 a,b;
    scanf("%lld %lld",&a,&b);
    printf("%lld",(a/gcd(a,b))*b);
}

int64 gcd(int64 a,int64 b)
{
    if(a==b||b<=0)return a;
    else if(a<b)return ((a<=0)?(b):(gcd(a,b%a)));
    else return gcd(b,a%b);
}
