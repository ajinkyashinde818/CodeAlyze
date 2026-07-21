#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> dp(2, vector<long long>(100001, 0));
 
int main() {
	int N; cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	dp[0][1] = A[0];
	dp[1][1] = -A[0];
	for (int i = 1; i < N; i++) {
		dp[0][i + 1] = max(dp[0][i] + A[i], dp[1][i] - A[i]);
		dp[1][i + 1] = max(dp[1][i] + A[i], dp[0][i] - A[i]);
	}
 
	cout << dp[0][N] << endl;
}
