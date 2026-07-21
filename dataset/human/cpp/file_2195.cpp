#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;

int main() {
    ll n;
    cin >> n;

    vl a(n);
    rep(i, n) {
        cin >> a[i];
    }

    vvl dp(n, vl(2, -INF));  // dp[i+1][j] : a[i]まで(iは0-index)の総和の最大値。ただし、j = 1 のとき a[i]とa[i+1]に操作を行ったとする
    dp[0][0] = 0;
    rep(i, n-1) {
        rep(j, 2) {
            chmax(dp[i+1][j], dp[i][j] + a[i]);
            chmax(dp[i+1][1-j], dp[i][j] - a[i]);
        }
    }

    out(max(dp[n-1][0] + a[n-1], dp[n-1][1] - a[n-1]));
    re0;
}
