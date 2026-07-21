#include <bits/stdc++.h>
using namespace std;

long long dp[5][3003];
int a[5];
int n;

int main(int argc, char const *argv[])
{
	// freopen("in", "r", stdin);
	cin >> a[1] >> a[2] >> a[3] >> n;
	dp[0][0] = 1;
	for(int i = 1; i <= 3; i++) {
		for(int j = 0; j <= n; j++) {
			if(j - a[i] >= 0) dp[i][j] += dp[i][j - a[i]];
			dp[i][j] += dp[i - 1][j];
		}
	}
	cout << dp[3][n] << endl;
	return 0;
}
