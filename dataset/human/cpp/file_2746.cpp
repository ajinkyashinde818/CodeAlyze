#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <functional>
#include <map>
#include <tuple>
using namespace std;

long long dp[200009][2], N, A[200009];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 0; i <= N; i++) { dp[i][0] = -(1LL << 60); dp[i][1] = -(1LL << 60); }
	dp[0][0] = 0;
	for (int i = 1; i <= N; i++) {
		if (dp[i - 1][0] != -(1LL << 60)) {
			dp[i][0] = max(dp[i][0], dp[i - 1][0] + A[i]);
			dp[i][1] = max(dp[i][1], dp[i - 1][0] - A[i]);
		}
		if (dp[i - 1][1] != -(1LL << 60)) {
			dp[i][1] = max(dp[i][1], dp[i - 1][1] + A[i]);
			dp[i][0] = max(dp[i][0], dp[i - 1][1] - A[i]);
		}
	}
	cout << dp[N][0] << endl;
	return 0;
}
