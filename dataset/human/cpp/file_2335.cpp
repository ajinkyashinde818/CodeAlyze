#include <bits/stdc++.h>

using namespace std;

int main() {
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
        int n;
        scanf("%d", &n);
        vector<long long> a(n + 10);
        for (int i = 1; i <= n; i++) {
                scanf("%lld", &a[i]);
        }
        vector<vector<long long>> dp(n + 10, vector<long long>(2, 0LL));
        dp[1][0] = a[1];
        dp[2][1] = -a[1] - a[2];
        dp[2][0] = a[1] + a[2];
        for (int i = 3; i <= n; i++) {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + a[i];
                long long fi = (i == 3 ? dp[i - 2][0] : max(dp[i - 2][0], dp[i - 2][1])) - a[i - 1] - a[i];
                dp[i][1] = max(fi, dp[i - 1][1] + 2LL * a[i - 1] - a[i]);
        }
        printf("%lld\n", max(dp[n][0], dp[n][1]));
        return 0;
}
