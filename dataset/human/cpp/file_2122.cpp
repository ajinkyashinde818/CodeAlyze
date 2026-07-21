#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef pair<P ,ll> P3;
typedef pair<P ,P> PP;
const ll MOD = 998244353;
const int IINF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = int(1e5 + 5);
const double EPS = 1e-6;
const int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define SORTR(v) sort((v).rbegin(), (v).rend())
#define ALL(v) (v).begin(), (v).end()

int main() {
    ll n, a[MAX_N], dp[MAX_N][2];
    cin >> n;
    REP(i,n) cin >> a[i];
    REP(i,n+1) dp[i][0] = dp[i][1] = -LLINF/3;
    dp[1][0] = a[0];
    for(int i=1;i<n;i++){
        dp[i+1][0] = max(dp[i][0], dp[i][1]) + a[i];
        dp[i+1][1] = max(dp[i][0]-a[i-1]*2, dp[i][1]+a[i-1]*2)-a[i];
    }
    cout << max(dp[n][0], dp[n][1]) << endl;
    return 0;
}
