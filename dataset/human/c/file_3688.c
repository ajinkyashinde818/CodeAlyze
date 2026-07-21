#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
ll gcd(ll a,ll b){ return b==0?a:gcd(b,a%b); }
int main(int argc,char *argv[])
{
    ll a,b;
    scanf("%lld%lld",&a,&b);
    printf("%lld",a*b/gcd(a,b));
    return 0;
}
