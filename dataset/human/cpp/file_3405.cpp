#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto& x : a){
		cin >> x;
	}
	vector<vector<long long>> dp(2,vector<long long>(n+2, 0));
	dp[1][1] = a[0]; dp[0][1] = -a[0];
	for(int i = 1; i < n-1; ++i){
		dp[1][i+1] = max(dp[1][i]+a[i], dp[0][i]-a[i]);
		dp[0][i+1] = max(dp[1][i]-a[i], dp[0][i]+a[i]);
	}
	cout << max(dp[1][n-1]+a[n-1], dp[0][n-1]-a[n-1]) << endl;
}
