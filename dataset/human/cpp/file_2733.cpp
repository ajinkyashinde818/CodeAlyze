#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, a[100008], dp[100008][2];

int main(){
	cin >> n;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	dp[1][0] = a[1];
	dp[1][1] = -a[1];
	for(ll i = 2; i <= n; i++){
		dp[i][0] = max(dp[i-1][0]+a[i], dp[i-1][1]-a[i]);
		dp[i][1] = max(dp[i-1][0]-a[i], dp[i-1][1]+a[i]);
	}
	
	cout << dp[n][0] << endl;
	return 0;
}
