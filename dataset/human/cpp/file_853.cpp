#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll r,g,b,n;
ll dp[5000];
ll ds(int n) {
	if(n == 0) return 1;
	if(n < 0) return 0;
	if(dp[n] != -1) return dp[n];
	ll tot = 0;
	if(!(n%b)) {tot++;}
	return dp[n] = tot+ds(n-g);
}
int main() {
	memset(dp,-1,sizeof(dp));
	cin >> r >> g >> b >> n;
	ll tot = 0;
	for(int i=0;i<=n;i++) {
		tot += ds(n-r*i);
	}
	cout << tot << '\n';
}
