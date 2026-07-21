#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int N;
	long long int dp[100001][2];
	cin >> N;
	int A[N];
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	dp[0][0] = 0;
	dp[0][1] = numeric_limits<long long int>::min() / 2; //what's this.
	for (int i = 0; i < N; i++)
	{
		dp[i+1][0] = max(dp[i][0] + A[i], dp[i][1] - A[i]);
		dp[i+1][1] = max(dp[i][0] - A[i], dp[i][1] + A[i]);
	}
	cout << dp[N][0] << endl;
	return 0;
}
