// Header {{{
#include <bits/stdc++.h>

using namespace std;
template<typename T>
using reversed_priority_queue = std::priority_queue<T, std::vector<T>, std::greater<T> >;
typedef unsigned long long int ull;
typedef long long int ll;
#define rep(i,a,b) for (ll i=(a); i<(b); i++)
typedef pair<ll,ll> PLL;
// }}}

signed main() {
    ll N,x=0,y=0,ans=1e10;
    cin>>N;
    vector<ll> v(N);
    rep(i,0,N){
        cin>>v[i];
        (i==0?x:y)+=v[i];
    }
    ans=abs(x-y);
    rep(i,1,N-1){
        x += v[i];
        y -= v[i];
        ans=min(ans, abs(x-y));
    }
    cout<<ans<<endl;
    return 0;
}
