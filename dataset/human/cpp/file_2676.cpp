#include <iostream>

using namespace std;

const int N = 1e5 + 5;

int a[N];
int n;
long long dp[N][2];


int main()
{
        cin >> n;
        for (int i=1; i<=n; i++) cin >> a[i];
        dp[0][0] = 0;
        dp[0][1] = -1e9;
        for (int i=1; i<=n; i++)
        {
                dp[i][0] = max(dp[i-1][0] + a[i], dp[i-1][1] - a[i]);
                dp[i][1] = max(dp[i-1][0] - a[i], dp[i-1][1] + a[i]);
        }
        cout << dp[n][0];
        return 0;
}
