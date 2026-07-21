#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <unordered_map>
#include <set>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int64_t> a;
	for (int i = 0; i < n; ++i) {
		int64_t ai;
		cin >> ai;
		a.push_back(ai);
	}
	const int64_t inf = 1ULL << 62;
	vector<vector<int64_t>> dp(n + 1, vector<int64_t>(3,-inf));
	dp[0][0] = 0;
	// 0 : not carry
	// 1 : carry
	for (int i = 0; i < n; ++i) {
		int64_t v1 = dp[i][0] + a[i];
		int64_t v2 = dp[i][1] - a[i];
		dp[i + 1][0] = max(max(v1, v2), -inf);

		int64_t v3 = dp[i][0] - a[i];
		int64_t v4 = dp[i][1] + a[i];
		dp[i + 1][1] = max(max(v3, v4), -inf);
	}
	cout << dp[n][0] << endl;
	return 0;
}
