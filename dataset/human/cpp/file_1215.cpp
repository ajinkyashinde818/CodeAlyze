#include<iostream>

using namespace std;
typedef long long ll;

int main() {
	int a, b, c, N;
	cin >> a >> b >> c >> N;
	ll dp[3000 + 4000][4] = {};
	dp[0][3] = 1;
	for (int i = 0; i <= N ; i++) {
		dp[i + a][0] += dp[i][0];
		dp[i + a][0] += dp[i][3];

		dp[i + b][1] += dp[i][1];
		dp[i + b][1] += dp[i][0];
		dp[i + b][1] += dp[i][3];

		dp[i + c][2] += dp[i][2];
		dp[i + c][2] += dp[i][1];
		dp[i + c][2] += dp[i][3];
		dp[i + c][2] += dp[i][0];
	}
	cout << dp[N][0] + dp[N][1] + dp[N][2] << endl;
	return 0;
}
