#include "bits/stdc++.h"

using namespace std;

void solve(void)
{
	int n;
	cin >> n;
	vector<long> as(n);
	for (long& a : as) cin >> a;
	vector<long> dp(2);
	dp[0] = as[0] + as[1];
	dp[1] = -dp[0];
	for (int i = 0; i < n-2; i++)
	{
		vector<long> nx(2);
		nx[0] = max(dp[0]+as[i+2], dp[1]+as[i+2]);
		nx[1] = max(dp[1]+2*as[i+1]-as[i+2], dp[0]-2*as[i+1]-as[i+2]);
		swap(dp, nx);
	}
	cout << max(dp[0], dp[1]) << endl;
}

int main()
{
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}
