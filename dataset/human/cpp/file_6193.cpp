#include <bits/stdc++.h>
using namespace std;

int main()
{
    int64_t n, c;
    cin >> n >> c;
    int64_t x[n], v[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> v[i];
    }
    int64_t dp[n + 1]{}, dp2[n + 1]{};
    for (int64_t i = 0, p = 0; i < n; i++)
    {
        dp[i + 1] = dp[i] + v[i] - (x[i] - p);
        p = x[i];
    }
    for (int64_t i = n - 1, p = c; 0 <= i; i--)
    {
        dp2[n - i] = dp2[n - i - 1] + v[i] - (p - x[i]);
        p = x[i];
    }
    int64_t puni[n + 1]{}, muni[n + 1]{};
    for (int i = 0; i < n; i++)
    {
        puni[i + 1] = max(puni[i], dp[i + 1]);
        muni[i + 1] = max(muni[i], dp2[i + 1]);
    }
    int64_t ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dp[i]);
        ans = max(ans, dp[i] + muni[n - i] - x[i - 1]);
        ans = max(ans, dp2[i]);
        ans = max(ans, dp2[i] + puni[n - i] - (c - x[n - i]));
    }
    cout << ans << endl;
    return 0;
}
