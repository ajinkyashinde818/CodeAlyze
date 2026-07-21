#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, a[maxn];
long long dp[maxn][3];
long long f(int pos, bool changed){
	if(pos == n) return 0;
	if(dp[pos][changed] != -1) return dp[pos][changed];
	long long val = a[pos];
	if(changed) val = -val;
	long long nocambio = val + f(pos + 1, 0);
	long long cambio = LLONG_MIN;
	if(pos + 1 < n) cambio = -val + f(pos + 1, 1);
	dp[pos][changed] = max(nocambio, cambio);
	return dp[pos][changed];
}
int main() {
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> a[i];
	memset(dp,-1,sizeof(dp));
	cout << f(0,0) << endl;
	return 0;
}
