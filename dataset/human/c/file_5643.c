#include <stdio.h>
int main(void){
    long long int x;
    long long int ans=0;
    scanf("%lld",&x);
    ans+=x/11;
    x%=11;
    if(x==0)printf("%lld",2*ans);
    else if(x<=6)printf("%lld",2*ans+1);
    else printf("%lld",2*ans+2);
    return 0;
}
