#include <iostream>
using namespace std;

int n;
long long c;
int v[100005];
long long x[100005];
long long dp[100005];
long long dp1[100005];
long long dp2[100005];
int main()
{
    cin >> n >> c;
    for(int i = 1; i <= n ; ++i) cin >> x[i] >> v[i];
    //ma duc clockwise
    long long Sol = 0;
    dp[1] = v[1] - x[1];
    Sol = max(Sol, dp[1]);
    dp1[1] = dp[1];
    for(int i = 2; i <= n ; ++i){
        dp[i] = dp[i - 1] + v[i] - (x[i] - x[i - 1]);
        Sol = max(Sol, dp[i]);
        dp1[i] = max(dp[i], dp1[i - 1]);
    }
    dp2[n] = x[n] + v[n] - c;
    Sol = max(Sol, dp2[n]);
    for(int i = n - 1; i >= 1 ; --i){
        dp2[i] = dp2[i + 1] + v[i] - (x[i + 1] - x[i]);
        Sol = max(Sol, dp2[i]);
    }
    for(int i = n; i > 1 ; --i)
        Sol = max(Sol, dp2[i] + dp1[i - 1] - (c - x[i]));
    for(int i = n - 1; i >= 1 ; --i)
        dp2[i] = max(dp2[i], dp2[i + 1]);
    for(int i = 1; i < n ; ++i){
        Sol = max(Sol, dp[i] + dp2[i + 1] - x[i]);

    }

    cout << Sol;

    return 0;
}
