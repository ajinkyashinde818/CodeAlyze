#include <stdio.h>
long long min(long long a,long long b){return a<b?a:b;}
int main(void){
    long long a,b,c,ans;
    scanf("%lld%lld%lld",&a,&b,&c);
    ans=b;
    ans+=min(b,c);
    c-=min(b,c);
    if (c>0){
        ans+=min(a,c);
        c-=a;
    }
    if (c>0){
        ans++;
    }
    printf("%lld\n",ans);
    return 0;
}
