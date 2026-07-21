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
    ll r, g, b, n;
    cin >> r >> g >> b >> n;
    ll res = 0;
    for (ll i = 0; i <= 3000;i++){
        for (ll j = 0; j <= 3000;j++){
            ll tmp = (n - r * i - g * j);
            if (tmp % b == 0 and tmp >= 0) res++;
        }
    }
    cout << res << endl;
}
