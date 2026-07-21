#include <bits/stdc++.h>
using namespace std;

int main()
{
	int64_t n;
	cin >> n;
	vector<int64_t> as(n);
	for (auto &a : as)
	{
		cin >> a;
	}

	vector<vector<int64_t>> dp(n, vector<int64_t>(2, -(1LL << 60)));
	dp[0][0] = 0;
	for (int64_t i = 0; i < n - 1; i++)
	{
		dp[i + 1][0] = max(dp[i][0] + as[i], dp[i][1] - as[i]);
		dp[i + 1][1] = max(dp[i][0] - as[i], dp[i][1] + as[i]);
	}

	cout << max(dp[n - 1][0] + as[n - 1], dp[n - 1][1] - as[n - 1]) << endl;

	return 0;
}
