#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
typedef long long ll;
int comb(int n,int k)
{
    ll t1=1ll,t2=1ll;
    for(int i=k+1;i<=n;++i) t1=(1ll*i*t1)%mod;
    for(int i=2;i<=n-k;++i) t2=(1ll*i*t2)%mod;
    ll usu=1ll,p=1ll*mod-2;
    while(p)
    {
        if(p&1) usu=(1ll*usu*t2)%mod;
        p=p>>1;
        t2=(t2*t2)%mod;
    }
    ll sol=0;
    sol=t1*usu%mod;
    return sol;
}
char c;
long long s[1003],n;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>c;
        ++s[c];
    }
    long long sol=1ll;
    for(char i='a';i<='z';++i)
    {
        sol=sol*1ll*(s[i]+1)%mod;
    }
    --sol;
    if(sol<0) sol+=mod;
    cout<<sol;
    return 0;
}
