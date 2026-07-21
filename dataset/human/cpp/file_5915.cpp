#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n;
ll c,a[N],b[N],pre[N],bk[N],pp[N],bb[N];
ll dis(ll x,ll y)
{
    return min(abs(x-y),c-abs(x-y));
}
ll solve()
{
    ll ans=0,pos=0,res=0;
    int l=1,r=n;
    while(l<=r)
    {
        if(b[l]-dis(pos,a[l])>b[r]-dis(pos,a[r]))
        {
            res+=b[l]-dis(pos,a[l]);
            ans=max(ans,res);
            pos=a[l++];
        }
        else
        {
            res+=b[r]-dis(pos,a[r]);
            ans=max(ans,res);
            pos=a[r--];
        }
    }
    return ans;
}
ll solve2()
{
    ll ans=0,pos=0,res=0;
    int l=1,r=n;
    while(l<=r)
    {
        if(dis(pos,a[l])<b[r]-dis(pos,a[r]))
        {
            res+=b[l]-dis(pos,a[l]);
            ans=max(ans,res);
            pos=a[l++];
        }
        else
        {
            res+=b[r]-dis(pos,a[r]);
            ans=max(ans,res);
            pos=a[r--];
        }
    }
    return ans;
}
int main()
{
    scanf("%d%lld",&n,&c);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&a[i],&b[i]);
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        pre[i]=pre[i-1]+b[i]-(a[i]-a[i-1]),ans=max(ans,pre[i]);
    }
    a[n+1]=c;
    for(int i=n;i>=1;i--)
        bk[i]=bk[i+1]+b[i]-(a[i+1]-a[i]),ans=max(ans,bk[i]);
    for(int i=n;i>=1;i--)
        bb[i]=max(bk[i],bb[i+1]);
    for(int i=1;i<=n;i++)
        pp[i]=max(pre[i],pp[i-1]);
    for(int i=n;i>=1;i--)
        ans=max(ans,bk[i]-(c-a[i])+pp[i-1]);
    for(int i=1;i<=n;i++)
        ans=max(ans,pre[i]-a[i]+bb[i+1]);
    ans=max(ans,solve());
    ans=max(ans,solve2());
    printf("%lld\n",ans);
}
