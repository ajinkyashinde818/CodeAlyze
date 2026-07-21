#include <bits/stdc++.h>

using namespace std;
const int mod=1e9+7;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e3+100;

ll a[maxn];
int main()
{
    ll n,k;
    scanf("%lld%lld",&n,&k);
    if(n>=10)
        cout<<k;
    else
        cout<<k+1000-100*n;
    //cout<<tot<<endl;
    return 0;
}
/*

ll qpow(ll x,ll y){
    ll sum=1;
    while(y){
        if(y&1)
            sum=sum*x%mod;
        y/=2;
        x=x*x%mod;
    }
    return sum;
}
ll C(ll n,ll m){
    ll low=min(m,n-m);
    ll H=1,L=1;
    for(int i=n-low+1;i<=n;i++)
        H=H*i%mod;
    for(int i=1;i<=low;i++)
        L=L*i%mod;
    return H*qpow(L,mod-2)%mod;
}
*/
