#include <bits/stdc++.h> 

using namespace std;
using ll = long long;

int main() {
	int N;
	cin >> N;
	vector<ll> a(N + 1);
	for (int i = 1; i <= N; ++i) { cin >> a[i]; }

	vector<vector<ll>> dp(N + 1, vector<ll>(2, -1e18));
	dp[1][0] = a[1];
	for (int i = 2; i <= N; ++i) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + a[i];
		dp[i][1] = max(dp[i - 1][0] - 2*a[i - 1], dp[i - 1][1] + 2*a[i - 1]) - a[i];
	}

	ll res = max(dp[N][0], dp[N][1]);
	cout << res << endl;

	return 0;
}
