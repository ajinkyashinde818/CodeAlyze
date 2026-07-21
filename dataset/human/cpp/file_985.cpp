#include <bits/stdc++.h>
using namespace std;

long long dp[3010];

int main(){
	int r, g, b, n;
	cin >> r >> g >> b >> n;
	dp[0] = 1;
	for (int i = r; i <= n; i++){
		dp[i] += dp[i - r];
	}
	for (int i = b; i <= n; i++){
		dp[i] += dp[i - b];
	}
	for (int i = g; i <= n; i++){
		dp[i] += dp[i - g];
	}
	cout << dp[n] << endl;
	return 0;
}
