#include<stdio.h>
#include<string.h>
int gcd(int a,int b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}
int main()
{
    long long int a,b,c;
    scanf("%lld %lld",&a,&b);
    if(b>a)
    {
        int tem=a;
        a=b;
        b=tem;
    }
    c=gcd(a,b);
    long long int ans;
    ans=a*b/c;
    printf("%lld\n",ans);
    return 0;
}
