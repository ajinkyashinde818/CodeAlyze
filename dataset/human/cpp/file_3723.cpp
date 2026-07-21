#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll inf = 1LL << 60;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll dp[n+1][2];
    dp[0][0] = 0;
    dp[0][1] = -inf;
    for (int i = 0; i < n; i++) {
        dp[i+1][0] = max(dp[i][0] + a[i], dp[i][1] - a[i]);
        dp[i+1][1] = max(dp[i][0] - a[i], dp[i][1] + a[i]);
    }
    cout << dp[n][0] << endl;
    return 0;
}
