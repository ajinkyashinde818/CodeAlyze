#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;
using INT = long long;

int main()
{
    int N;
    cin >> N;

    vector<INT> As(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> As[i];
    }

    map<pair<int, int>, INT> dp;
    dp[{ -1, 0 }] = 0;
    dp[{ -1, 1 }] = -LLONG_MAX / 2;

    for (int i = 0; i < N - 1; ++i)
    {
        dp[{i, 0}] = max(dp[{i - 1, 0}] + As[i], dp[{i - 1, 1}] - As[i]);
        dp[{i, 1}] = max(dp[{i - 1, 0}] - As[i], dp[{i - 1, 1}] + As[i]);
    }
    const auto ans = max(dp[{N - 2, 0}] + As.back(), dp[{N - 2, 1}] - As.back());
    cout << ans;

    return 0;
}
