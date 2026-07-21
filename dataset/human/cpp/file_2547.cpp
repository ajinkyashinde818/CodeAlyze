#include<iostream>
using namespace std;
typedef long long ll;

const int MAX_N = 1e5 + 10;
const ll INF = 1LL << 50;

ll A[MAX_N], dp[MAX_N][2][2];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 1; i <= N ; i++) cin >> A[i];
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) dp[i][j][k] = -INF;
        }
    }
    for (int i = 1; i <= N; i++) {
        ll tmp = 0;
        if (dp[i - 1][0][0] > -INF) tmp = dp[i - 1][0][0];
        if (dp[i - 1][1][0] > -INF) tmp = max(tmp, dp[i - 1][1][0]);
        dp[i][0][0] = tmp + A[i];
        if (i > 1) {
            tmp = 0;
            if (dp[i - 1][0][1] > -INF) tmp = dp[i - 1][0][1];
            if (dp[i - 1][1][1] > -INF) tmp = max(tmp, dp[i - 1][1][1]);
            dp[i][1][0] = tmp - A[i];
        }
        if (i == N) break;
        tmp = 0;
        if (dp[i - 1][0][0] > -INF) tmp = dp[i - 1][0][0];
        if (dp[i - 1][1][0] > -INF) tmp = max(tmp, dp[i - 1][1][0]);
        dp[i][0][1] = tmp - A[i];
        if (i > 1) {
            tmp = 0;
            if (dp[i - 1][0][1] > -INF) tmp = dp[i - 1][0][1];
            if (dp[i - 1][1][1] > -INF) tmp = max(tmp, dp[i - 1][1][1]);
            dp[i][1][1] = tmp + A[i];
        }
    }
    cout << max(dp[N][0][0], dp[N][1][0]) << endl;
    return 0;
}
