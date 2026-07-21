// #pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using vii = vector<int>;
using pii = pair<int, int>;
template <typename T = vii> 
using vec = vector<T>;

const ll INF = numeric_limits<ll>::max(),
         MOD = 1e9 + 7;

const int INF_i = numeric_limits<int>::max(),
          MAX = 1e6;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    // freopen("in.in", "r", stdin);
    
    int n;
    cin >> n;
    vll v(n), dp[2];
    for (auto &e : v) {
        cin >> e;
    }
    dp[0].assign(n, 0);
    dp[1].assign(n, 0);
    dp[0][0] = v[0];
    dp[1][0] = -1e10;
    for (int i = 1; i < n; i++) {
        dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]) + v[i];
        dp[1][i] = max(dp[0][i - 1] - 2 * v[i - 1], dp[1][i - 1] + 2 * v[i - 1]) - v[i];
    }
    cout << max(dp[0].back(), dp[1].back())<< '\n';
}
