#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repr(i, n) for (ll i = n; i >= 0; i--)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define INIT    \
    cin.tie(0); \
    ios::sync_with_stdio(false);

template <class T>
inline bool chmax(T& a, T b) {
    return a = (a < b) ? b : a;
}
template <class T>
inline bool chmin(T& a, T b) {
    return a = (a > b) ? b : a;
}

ll const INF = 1LL << 60;
ll const MOD = 1000000007;

int main() {
    INIT;

    vector<ll> c(3);
    ll N;
    cin >> c[0] >> c[1] >> c[2] >> N;

    sort(ALL(c), greater<ll>());

    ll ans = 0;

    ll ni = N / c[0];
    rep(i, ni + 1) {
        ll resi = N - i * c[0];
        ll nj = resi / c[1];
        rep(j, nj + 1) {
            ll resj = resi - j * c[1];
            // cout << "(" << i << ", " << j << ") res:" << resj << endl;
            if (resj % c[2] == 0) {
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
