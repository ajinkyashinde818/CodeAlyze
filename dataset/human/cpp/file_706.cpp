#include<bits/stdc++.h>
using namespace std;
const int maxn = 300001;
long long dp[3001];
int main(){
	// ios_base::sync_with_stdio(0), cin.tie(0);
	int r, g, b, n;
	dp[0] = 1;
	cin >> r >> g >> b >> n;
	for(int i = r;i <= n;++i){
		if(dp[i - r])dp[i] += dp[i - r];
	}
	for(int i = g;i <= n;++i){
		if(dp[i - g])dp[i] += dp[i - g];
	}
	for(int i = b;i <= n;++i){
		if(dp[i - b])dp[i] += dp[i - b];
	}
	cout << dp[n];
}
