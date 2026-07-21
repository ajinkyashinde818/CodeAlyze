#include <stdio.h>
int main(void)
{
    long long int x,ans=0;
    scanf("%lld", &x);
    ans+=(x-(x%11))/11*2;
    if(x%11>=7) ans+=2;
    else if(x%11==0) ans+=0;
    else ans++;
    printf("%lld", ans);
    return 0;
}
