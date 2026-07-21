#include <iostream>
#include <vector>

const int N_MAX = 1e5 + 10;

typedef long long ll;

using namespace std;


int main() {
    int n;
    cin >> n;
    ll dp[N_MAX][2] = {0};
    int a[N_MAX];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    dp[0][0] = a[0];
    dp[0][1] = -a[0];
    for (int i=1; i<n-1; ++i) {
        dp[i][0] = max(dp[i-1][0] + a[i], dp[i-1][1] - a[i]);
        dp[i][1] = max(dp[i-1][0] - a[i], dp[i-1][1] + a[i]);
    }

    cout << max(dp[n-2][0] + a[n-1], dp[n-2][1] - a[n-1]) << endl;
}
