#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    long long a[n];
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    long long dp[n + 1][2];
    
    dp[0][0] = 0;
    dp[0][1] = -100000000000000;
    
    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][0] + a[i - 1], dp[i - 1][1] - a[i - 1]);
        dp[i][1] = max(dp[i - 1][0] - a[i - 1], dp[i - 1][1] + a[i - 1]);
    }
    
    cout << dp[n][0] << endl;
}
