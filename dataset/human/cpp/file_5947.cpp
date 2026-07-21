#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;
ll n,c,x[N],w[N],val[N],rval[N],shun[N],ni[N];
int main()
{
    cin>>n>>c;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i]>>w[i];
        val[i]=val[i-1]+w[i];//顺着到i的价值总和
        shun[i]=max(shun[i-1],val[i]-x[i]);//顺着到i取最大
    }
    for(int i=n;i>=1;i--)
    {
        rval[i]=rval[i+1]+w[i];//逆着到i的价值总和
        ni[i]=max(ni[i+1],rval[i]-c+x[i]);//逆着到i取最大
    }
    ll maxx=0;
    for(int i=n;i>=1;i--)
    {
        maxx=max(maxx,rval[i]-2*(c-x[i])+shun[i-1]);//先逆着到i，再顺着到i-1
        maxx=max(maxx,ni[i]);//只有逆
    }
    for(int i=1;i<=n;i++)
    {
        maxx=max(maxx,val[i]-2*x[i]+ni[i+1]);//先顺着到i，再逆着到i+1
        maxx=max(maxx,shun[i]);//只有顺
    }
    cout<<maxx;
    return 0;
}
