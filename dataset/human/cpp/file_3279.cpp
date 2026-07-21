#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<vector<ll>> dp(2, vector<ll>(N + 1, 0));
    dp[1][0] = INT_MIN;

    for (ll i = 0; i < N; i++) {
        //操作する
        dp[1][i + 1] = max(dp[0][i] - A[i], dp[1][i] + A[i]);

        //操作しない
        dp[0][i + 1] = max(dp[0][i] + A[i], dp[1][i] - A[i]);
    }

    cout << dp[0][N] << endl;
}
