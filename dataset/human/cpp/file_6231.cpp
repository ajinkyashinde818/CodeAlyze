#include <bits/stdc++.h>
using namespace std;

long long dp[100010];
long long dp2[100010];
long long x[100010], v[100010];
long long n, C;

int main()
{
    cin >> n >> C;

    for (long long i(1); i <= n; i++) {
        cin >> x[i] >> v[i];
        dp[i] = dp[i - 1] - x[i] + x[i - 1] + v[i];
        dp2[i] = dp2[i - 1] - 2 * x[i] + 2 * x[i - 1] + v[i];
    }
    x[n + 1] = C;

    for (long long i(1); i <= n; i++) {
        dp[i] = max(dp[i], dp[i - 1]);
        dp2[i] = max(dp2[i], dp2[i - 1]);
    }

    long long best(dp[n]), act(0), act2(0);

    for (long long i(n); i >= 1; i--) {
        act += v[i];
        act += -x[i + 1] + x[i];
        act2 += v[i];
        act2 += -2 * x[i + 1] + 2 * x[i];
        best = max(best, max(act + dp2[i - 1], act2 + dp[i - 1]));
    }

    cout << best << '\n';
    return 0;
}
