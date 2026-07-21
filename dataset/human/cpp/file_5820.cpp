#include<cstdio>
#include<deque>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;
const int MAXN=100000+5;
const int INF=0x3f3f3f3f;

LL x[MAXN],v[MAXN];
LL dp1[MAXN],dp2[MAXN];

int main()
{
    LL n,c;
    cin>>n>>c;
    for(int i=1;i<=n;i++)
        cin>>x[i]>>v[i];
    LL sm=0;
    for(int i=1;i<=n;i++)
    {
        sm+=v[i]-(x[i]-x[i-1]);
        dp1[i]=max(sm,dp1[i-1]);
    }
    x[n+1]=c;
    sm=0;
    for(int i=n;i>=1;i--)
    {
        sm+=v[i]-(x[i+1]-x[i]);
        dp2[i]=max(sm,dp2[i+1]);
    }
    LL ans=max(dp1[n],dp2[1]);
    for(int i=n;i>=2;i--)
        ans=max(ans,dp2[i]+dp1[i-1]-(c-x[i]));
    for(int i=1;i<=n-1;i++)
        ans=max(ans,dp1[i]-x[i]+dp2[i+1]);
    cout<<ans<<endl;
    return 0;
}
