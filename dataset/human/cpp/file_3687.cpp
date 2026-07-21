//besmellah
#include <bits/stdc++.h>
using namespace std;
// __builtin_popcount

const long long inf  = 1e12;
vector <long long> A, dp, au;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	A.resize(n);
	dp.resize(n);
	au.resize(n);
	for (int i = 0; i < n; i++){
		cin >> A[i];
	}
	dp[0] = A[0];
	au[0] = -1 * A[0];
	for (int i = 1; i < n; i++){
		dp[i] = max(au[i - 1], dp[i - 1]) + A[i];
		au[i] = max(au[i - 1] + 2 * A[i - 1], dp[i - 1] - 2 * A[i - 1]) - A[i];
		if (i == 1){
			dp[i] = dp[0] + A[1];
			au[i] = au[0] - A[1];
		}
		// cout << i << ' ' << dp[i] << ' ' << au[i] << '\n';
	}
	cout << max(dp[n - 1], au[n - 1]);
}
