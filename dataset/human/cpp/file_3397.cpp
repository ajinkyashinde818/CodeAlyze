#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    const int MAX_NUM = (int) 1e9 + 1;
    
    ll dp[N + 1][2];
    dp[0][0] = 0;
    dp[0][1] = - MAX_NUM;

    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        dp[i + 1][0] = max(dp[i][0] + a, dp[i][1] - a);
        dp[i + 1][1] = max(dp[i][0] - a, dp[i][1] + a);
    }

    
    
    cout << dp[N][0] << '\n';

    return 0;
}
