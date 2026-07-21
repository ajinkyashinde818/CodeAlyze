#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll inf = 1e18;

int main() {
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(2, -inf));
    dp[0][0] = a[0];
    for(int i = 1; i < n; ++i) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + a[i];
        dp[i][1] = max(dp[i - 1][0] - a[i - 1] + (-a[i - 1] - a[i]), dp[i - 1][1] + a[i - 1] + (a[i - 1] - a[i]));
    }
    cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
}
