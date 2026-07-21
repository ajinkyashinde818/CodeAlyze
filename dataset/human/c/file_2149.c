#include <stdio.h>
int main()
{   long long n;
    scanf("%lld",&n);
    if(n%2){
        printf("0");
        return 0;
    }
    long long ans=0;
    long long d=10;
    while(n>=d){
        ans+=n/d;
        d*=5;
    }
    printf("%lld",ans);
    
    
    return 0;
}
