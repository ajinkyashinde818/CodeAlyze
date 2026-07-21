#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N;

void solve() {
    cin >> N;
    ll A[N];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    vector<vector<ll>> dp(N+1, vector<ll>(2, 0));
    dp[0][1] = -1e11;
    for (int i = 0; i < N; ++i) {
        ll a = A[i];
        dp[i+1][0] = max(dp[i][0] + a, dp[i][1] - a);
        dp[i+1][1] = max(dp[i][0] - a, dp[i][1] + a);
    }
    cout << dp[N][0] << endl;
}

int main() {
    solve();
    return 0;
}
