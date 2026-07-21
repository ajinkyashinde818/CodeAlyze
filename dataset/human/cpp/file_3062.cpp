#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int>	a(n); for (auto&& x : a)cin >> x;

	vector< vector<long long> > dp(n+1, vector<long long>(2));
	dp[0][0] = 0; dp[0][1] = (int)-1e9;
	for (int i = 0; i < n; i++) {
		dp[i+1][0] = max(dp[i][0] + a[i], dp[i][1] - a[i]);
		dp[i+1][1] = max(dp[i][1] + a[i], dp[i][0] - a[i]);
	}
	cout << dp[n][0] << endl;

	return 0;
}
