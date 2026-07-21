#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr long long MOD = 1000000007;
constexpr long long INF = 1LL << 60;
const long double PI = acosl(-1.0);
constexpr long double EPS = 1e-11;
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
int main(){
ll n;
cin >> n;
ll a[n];
ll cum[n + 1];
cum[0] = 0;
for (ll i = 0; i < n; i++){
    cin >> a[i];
    cum[i + 1] = cum[i] + a[i];
}
ll ans = INF;
for (ll i = 1; i < n; i++) {
    ll tmp = abs(2*cum[i]-cum[n]);
    chmin(ans, tmp);
}
cout << ans << endl;
}
