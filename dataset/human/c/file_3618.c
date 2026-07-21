#include<stdio.h>
#include<math.h>
#define ll long long
int main()
{
    ll a,b,c,d,ans;
    while(~scanf("%lld%lld",&a,&b));
    {
        ll t,r=1;
        ll j;
        c=a;d=b;
        if(a<b)
        {
            t=a;
            a=b;
            b=t;
        }
        while(r)
        {
            r=a%b;
            j=b;
            a=b;
            b=r;
        }
        ans=c/j*d;
        printf("%lld\n",ans);
    }
}
