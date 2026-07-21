//code by lynmisakura.wish to be accepted!
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void){
    ll n;scanf("%lld",&n);
    vector<ll> a(n);
    for(int i = 0;i < n;i++)scanf("%lld",&a[i]);

    vector<ll> c(n+1,0);
    for (int i = 0; i < n; ++i)
    {
        c[i+1] = c[i]+a[i];
    }
    ll ans = LONG_MAX;
    for(ll i = 1;i <= n-1;i++){
        ans = min(ans,abs((c[n]-c[i]) - c[i]));
    }
    printf("%lld\n",ans);
}
