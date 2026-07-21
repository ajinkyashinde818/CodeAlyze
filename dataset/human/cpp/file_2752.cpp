#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 1000000007;
constexpr long long INF = 1LL << 60;
const long double PI = acosl(-1.0);
using ll = long long;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    ll minus = 0;
    for (ll i = 0; i < n;i++){
        if (a[i] < 0) minus++;
    }
    ll ans = 0;
    if (minus % 2 == 0) {
        for (ll i = 0; i < n; i++) ans += abs(a[i]);
    }
    else{
        ll minn = INF;
        for (ll i = 0; i < n;i++){
            chmin(minn, abs(a[i]));
        }
        for (ll i = 0; i < n; i++) ans += abs(a[i]);
        ans -= 2 * minn;
    }
    cout << ans << endl;
}
