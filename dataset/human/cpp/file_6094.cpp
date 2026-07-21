#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
long long x[maxn+5],a[maxn+5];
long long sum[maxn+5],ans;
int n;
long long c;
multiset<long long> s;
int main()
{
    scanf("%d%lld",&n,&c);
    for(int i=1;i<=n;++i) scanf("%lld%lld",&x[i],&a[i]);
    ans=0;
    for(int i=1;i<=n;++i)
    {
        sum[i]=sum[i-1]+a[i];
        ans=max(ans,sum[i]-x[i]);
    }
    for(int i=1;i<=n;++i) ans=max(ans,sum[n]-sum[i-1]-(c-x[i]));
    //printf("%lld\n",ans);
    for(int i=1;i<=n;++i)
        s.insert(sum[n]-sum[i-1]-(c-x[i]));
    for(int i=1;i<n;++i)
    {
        long long now=sum[i]-2*x[i];
        s.erase(s.find(sum[n]-sum[i-1]-(c-x[i])));
        ans=max(ans,now+*s.rbegin());
        //printf("%lld %lld\n",now,*s.rbegin());
    }
    s.clear();
    for(int i=1;i<=n;++i) s.insert(sum[i]-x[i]);
    for(int i=n;i>1;--i)
    {
        long long now=sum[n]-sum[i-1]-2*(c-x[i]);
        s.erase(s.find(sum[i]-x[i]));
        ans=max(ans,now+*s.rbegin());
    }
    printf("%lld\n",ans);
    return 0;
}
