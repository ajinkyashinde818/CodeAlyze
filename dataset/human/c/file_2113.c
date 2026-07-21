#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    long long n,pow=5,ans=0;

    scanf("%lld",&n);

    if(n%2==1) printf("%d",0);
    else
    {
        n=n/2;
        while(pow<=n)
        {
            ans+=n/pow;
            pow*=5;
        }
        printf("%lld",ans);
    }

    return 0;
}
