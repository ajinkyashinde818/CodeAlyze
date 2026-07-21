#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1LL<<60;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<long long> > dp(n + 1, vector<long long>(2, -INF));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        dp[i + 1][0] = max(dp[i][0] + a[i], dp[i][1] - a[i]);
        dp[i + 1][1] = max(dp[i][0] - a[i], dp[i][1] + a[i]);
    }

    cout << dp[n][0] << endl;
    return 0;
}
