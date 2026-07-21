#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAX_N = 1e5+10;
const long long INF = 0x3f3f3f3f3f3f3f3f;
int N, a[MAX_N];
ll dp[MAX_N][2];

void solve()
{
    //dp[i][j]: max value a[0]..a[i-1], j sign before a[i] is changed?
	dp[1][0]=a[0];
	dp[1][1]=-a[0];
	for(int i=1;i<N;++i){
		dp[i+1][0] = max(dp[i][0]+a[i], dp[i][1]-a[i]);
		dp[i+1][1] = max(dp[i][0]-a[i], dp[i][1]+a[i]);
	}
	cout << dp[N][0] << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> N;
	for(int i=0;i<N;++i)cin>>a[i];
	solve();
	return 0;
}
