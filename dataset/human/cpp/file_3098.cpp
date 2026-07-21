/*---------------------------------

 @Author:   Dicer
 @DateTime: 2019-05-12 11:45:41

---------------------------------*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
inline ll qpow(ll a,ll b,ll mod){ll res=1;while(b){if(b&1)res = (res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const int MAXN = 2e5 + 7;

int a[MAXN];
ll dp[MAXN][2][2];
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)	cin >> a[i];
	for(int i = 1; i <= n; ++i){
		dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = -INF; 
	}
	dp[1][0][0] = a[1]; dp[1][0][1] = -a[1];
	// dp[1][1][0] = -a[1]; dp[1][1][1] = a[1];
	for(int i = 2; i < n; ++i){
		dp[i][0][1] = max(dp[i-1][1][0], dp[i-1][0][0]) - a[i];
		dp[i][0][0] = max(dp[i-1][1][0], dp[i-1][0][0]) + a[i];
		dp[i][1][1] = max(dp[i-1][1][1], dp[i-1][0][1]) + a[i];
		dp[i][1][0] = max(dp[i-1][1][1], dp[i-1][0][1]) - a[i];
	}
	dp[n][1][0] = max(dp[n-1][0][1], dp[n-1][1][1]) - a[n];
	dp[n][0][0] = max(dp[n-1][0][0], dp[n-1][1][0]) + a[n];
	cout << max(dp[n][1][0], dp[n][0][0]) << endl;
	// for(int i = 1; i <= n; ++i){
		// cout << max(max(dp[i][1][0], dp[i][0][0]), max(dp[i][1][1], dp[i][0][1])) << endl;
	// }
	return 0;
}
