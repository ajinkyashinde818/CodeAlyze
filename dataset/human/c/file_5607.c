#include <stdio.h>

int main()
{   long long x;
    scanf("%lld",&x);
    long long ans=x/11*2;
    if(x%11==0)
    printf("%lld",ans);
    else if(x%11<=6)
    printf("%lld",ans+1);
    else printf("%lld",ans+2);
    
}
