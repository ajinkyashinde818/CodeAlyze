#include <stdio.h>

typedef long long int llint;

llint gcd(llint a,llint b)
{
    if(a<b)
    {
        int tmp=a;
        a=b;
        b=tmp;
    }
    if(a%b==0)return b;
    else return gcd(b,a%b);
}

int main()
{
    llint a,b;
    scanf("%lld %lld",&a,&b);
    printf("%lld\n",a*b/gcd(a,b));
}
