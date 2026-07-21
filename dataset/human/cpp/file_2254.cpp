#include <bits/stdc++.h>
using namespace std;
 
// https://atcoder.jp/contests/abc125/tasks/abc125_d
void Solve02()
{
    int n;
    cin >> n;
    long long a[n + 1], dp[n + 1][2];
    dp[0][0] = 0, dp[0][1] = -1e10;
    for (int i = 1; i < n + 1; i++)
        cin >> a[i];
    for (int i = 1; i < n + 1; i++)
    {
        dp[i][0] = max((dp[i - 1][0] + a[i]), (dp[i - 1][1] - a[i]));
        dp[i][1] = max((dp[i - 1][0] - a[i]), (dp[i - 1][1] + a[i]));
        // cout << dp[i][0] << " " << dp[i][1] << endl;
    }
    cout << dp[n][0];
}
 
int main()
{
    Solve02();
}
