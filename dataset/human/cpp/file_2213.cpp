#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <cstdio>
#include <numeric>

using namespace std;

long long dp[100005][2];
long long N;
long long A[100005];
const long long inf = 1e15;

int main()
{
    cin >> N;
    for (int i = 1; i <= N;i++)
    {
        cin >> A[i];
    }
    for (long long i = 0; i < N;i++)
    {
        dp[i][0] = -inf;
        dp[i][1] = -inf;
    }
    dp[0][0] = 0;
    for (long long i = 1; i <= N;i++)
    {
        dp[i][0] = max(dp[i][0], dp[i - 1][0] + A[i]);
        dp[i][0] = max(dp[i][0], dp[i - 1][1] - A[i]);

        dp[i][1] = max(dp[i][1], dp[i - 1][0] - A[i]);
        dp[i][1] = max(dp[i][1], dp[i - 1][1] + A[i]);
    }
    cout << dp[N][0] << endl;
    return 0;
}
