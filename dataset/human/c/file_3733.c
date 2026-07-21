#include<stdio.h>
#include<string.h>
long long gcd(long long a, long long b){
    return b==0 ? a : gcd(b,a%b);
}
int main()
{
    long long a,b,c;

    scanf("%lld %lld",&a,&b);
    c=gcd(a,b);
    printf("%lld",(a*b)/c);
    return 0;
}
