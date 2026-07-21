#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;

    vector<ll> arr(n);
    ll dp[n+1][2];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dp[1][0] = arr[0] + arr[1];
    dp[1][1] = -arr[0] - arr[1];

    for (int i = 2; i < n; i++) {
        dp[i][0] = max(dp[i-1][0] + arr[i], dp[i-1][1] + arr[i]);
        dp[i][1] = max(dp[i-1][0] - 2*arr[i-1] - arr[i], dp[i-1][1] + 2*arr[i-1] - arr[i]);
    }
    cout << max(dp[n-1][0], dp[n-1][1]) << endl;
}
