#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll A[100001];
ll dp[2][2][100001];

int main() {
	int n;
	while (cin >> n) {
		for (int i = 0; i < n; ++i) {
			cin >> A[i];
		}
		dp[0][0][0] = dp[1][0][0] = A[0];
		dp[0][1][0] = dp[1][1][0] = -A[0];
		
		for (int i = 1; i < n; ++i) {
			dp[0][0][i] = max(dp[0][0][i-1] + A[i], dp[1][0][i-1] + A[i]);
			dp[1][0][i] = max(dp[0][1][i-1] - A[i], dp[1][1][i-1] - A[i]);
			dp[0][1][i] = max(dp[0][0][i-1] - A[i], dp[1][0][i-1] - A[i]);
			dp[1][1][i] = max(dp[0][1][i-1] + A[i], dp[1][1][i-1] + A[i]);
		}
		
		cout << max(dp[0][0][n-1], dp[1][0][n-1]) << endl;
	}
	return 0;
}
