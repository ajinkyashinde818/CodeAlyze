#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

void solve(long long N, std::vector<long long> a){
    vector<ll> cumsum(N+1, 0);
    for(ll i = 0; i < N; ++i) cumsum[i+1] = cumsum[i] + a[i];
    ll ans = INF;
    //for(auto a : cumsum) cout << a << " ";
    //cout << endl;
    for(ll i = 1; i < N; ++i){
        //cout << cumsum[i] << " " << (cumsum[N] - cumsum[i]) << endl;
        ans = min(ans, abs(cumsum[i] - (cumsum[N] - cumsum[i])));
    }
    cout << ans << endl;
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> a(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&a[i]);
    }
    solve(N, std::move(a));
    return 0;
}
