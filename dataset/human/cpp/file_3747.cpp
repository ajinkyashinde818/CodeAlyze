#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    long long A[N], dp[N + 1][2];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        dp[i][0] = 0;
        dp[i][1] = 0;
    }
    dp[0][1] = -1000000007;
    for (int i = 0; i < N; i++) {
        dp[i + 1][0] = max(dp[i][0] + A[i], dp[i][1] - A[i]);
        dp[i + 1][1] = max(dp[i][0] - A[i], dp[i][1] + A[i]);
    }
    cout << dp[N][0] << endl;
}
