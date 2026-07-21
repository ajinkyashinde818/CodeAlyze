#include <bits/stdc++.h>

using namespace std;

signed main() {
    long long n;
    cin >> n;
    long long c[n], dp0[n + 1], dp1[n + 1];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    dp0[0] = dp1[0] = 0;
    dp0[1] = c[0]; dp0[2] = c[0] + c[1]; dp1[1] = 0; dp1[2] = -c[0] - c[1];
    for (int i = 3; i <= n; i++) {
        dp0[i] = max(dp0[i - 1], dp1[i - 1]) + c[i - 1];
        dp1[i] = max(dp0[i - 1] - 2 * c[i - 2], dp1[i - 1] + 2 * c[i - 2]) - c[i - 1];
    }
    cout << max(dp0[n], dp1[n]);
    return 0;
}
