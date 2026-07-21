#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;


int main() {
    int N; cin >> N;
    vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];

    long long dp[N + 1][2];
    for (int i = 0; i < N + 1; i++) for (int j = 0; j < 2; j++) dp[i][j] = 0;
    dp[0][1] = - INF;

    for (int i = 0; i < N; i++) {
        dp[i + 1][0] = max(dp[i][0] + A[i], dp[i][1] - A[i]);
        dp[i + 1][1] = max(dp[i][0] - A[i], dp[i][1] + A[i]);
    }

    cout << dp[N][0] << endl;
    return 0;
}
