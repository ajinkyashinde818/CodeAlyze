#include <stdio.h>

const int mod = 1000000007;
int N;
int M;
int a[100005];
int dp[100005];
int a_cur = 0;

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; ++i) scanf("%d", &a[i]);

	dp[0] = 1;

	for (int i = 1; i <= N; ++i)
	{
		if (i == a[a_cur])
		{
			a_cur++;
			continue;
		}
		if (i - 1 >= 0) dp[i] = (dp[i] + dp[i - 1]) % mod;
		if (i - 2 >= 0) dp[i] = (dp[i] + dp[i - 2]) % mod;
	}

	printf("%d\n", dp[N]);

	return 0;
}
