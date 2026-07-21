#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0;i < n;i++){
        cin >> a[i];
    }

    ll sum = 0;
    for (ll i = 0; i < n; i++){
        sum += a[i];
    }

    ll x = (sum - a[n-1]);
    ll y = a[n-1];
    ll ans = abs(x-y);

    for (ll i = n-2; i > 0; i--){
        x -= a[i];
        y += a[i];
        ans = min(ans, abs(x-y));
    }

    cout << ans << endl;

}
