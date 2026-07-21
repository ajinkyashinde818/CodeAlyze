#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr) {
        cin >> x;
    }
    vector<vector<ll> > dp(2, vector<ll>(n));
    dp[0][n-1] = arr[n-1];
    dp[1][n-1] = -arr[n-1];
    for (int i = n-2; i >= 0; --i) {
        dp[0][i] = max(arr[i]+dp[0][i+1], -arr[i]+dp[1][i+1]);
        dp[1][i] = max(-arr[i]+dp[0][i+1], arr[i]+dp[1][i+1]);
    }
    cout << dp[0][0] << "\n";
}
