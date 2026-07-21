#include <stdio.h>
#include <math.h>

typedef long long int llint;

int main()
{
    llint n;
    scanf("%lld",&n);
    
    if(n&1)
    {
        printf("0\n");
        return 0;
    }
    llint ans=0;

    for(llint i=10;i<=n;i*=5)
    {
        ans+=(llint)n/i;
    }
    printf("%lld\n",ans);
}
