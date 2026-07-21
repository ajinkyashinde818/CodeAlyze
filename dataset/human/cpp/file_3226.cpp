#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    long long int n;
    cin >> n;

    vector<long long int> a(n);
    for (long long int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector< vector<long long int> > dp(n, vector<long long int>(2, 0));
    dp[1][0] = a[0]+a[1];
    dp[1][1] = -(a[0]+a[1]);

    for (long long int i = 2; i < n; i++) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]) + a[i];
        dp[i][1] = max(dp[i-1][0]-2*a[i-1], dp[i-1][1]+2*a[i-1]) - a[i];
        //cout << dp[i][0] << ' ' << dp[i][1] << endl;
    }

    cout << max(dp[n-1][0], dp[n-1][1]) << endl;
    return 0;
}
