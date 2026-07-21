#include <bits/stdc++.h>
using namespace std;

int n;
long long a[100010];
long long memo[100010][2];
long long dp(int pos, int nxt) {
    if (pos == n) return 0;
    if (memo[pos][nxt] != -1) return memo[pos][nxt];
        long long ans = - 1LL << 30;
    if (!nxt) {
        ans = a[pos] + dp(pos + 1, 0);
        if (pos != n - 1) ans = max(ans, -a[pos] + dp(pos + 1, 1));
    } else {
        ans = -a[pos] + dp(pos + 1, 0);
        if (pos != n - 1) ans = max(ans, a[pos] + dp(pos + 1, 1));
    }
    return memo[pos][nxt] = ans;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    memset(memo, -1, sizeof(memo));
    cout << dp(0, 0) << "\n";
    return 0;
}
