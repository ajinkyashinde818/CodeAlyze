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
        val[i]=val[i-1]+w[i];
        shun[i]=max(shun[i-1],val[i]-x[i]);
    }
    for(int i=n;i>=1;i--)
    {
        rval[i]=rval[i+1]+w[i];
        ni[i]=max(ni[i+1],rval[i]-c+x[i]);
    }
    ll A=0;
    for(int i=n;i>=1;i--)
    {
        A=max(A,rval[i]-2*(c-x[i])+shun[i-1]);
        A=max(A,ni[i]);
    }
    for(int i=1;i<=n;i++)
    {
        A=max(A,val[i]-2*x[i]+ni[i+1]);
        A=max(A,shun[i]);
    }
    cout<<A;
    return 0;
}
