#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
const ll INF = 1LL << 60;
const ll MOD = (ll) 1e9 + 7;

int main(){
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    ll sum = accumulate(v.begin(), v.end(), 0LL);
    ll snuke = 0;
    ll ans = INF;
    for (int i = 0; i < n - 1; i++) {
        snuke += v[i];
        ans = min(ans, abs(snuke * 2 - sum));
    }
    cout << ans << "\n";
}
