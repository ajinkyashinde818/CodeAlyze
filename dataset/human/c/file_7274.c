#include<stdio.h>
int main()
{
	int h, w;
	scanf("%d %d", &h, &w);
	int i, j, k;
	int a[88][88], b[88][88];
	for (i = 0; i < h; i++)
		for (j = 0; j < w; j++)
			scanf("%d", &a[i][j]);
	for (i = 0; i < h; i++)
		for (j = 0; j < w; j++)
			scanf("%d", &b[i][j]);
	int d[88][88];
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			if (a[i][j] > b[i][j])
				d[i][j] = a[i][j] - b[i][j];
			else
				d[i][j] = b[i][j] - a[i][j];
		}
	}
	int dp[2][88][26000];
	for (i = 0; i < w; i++)
		for (k = 0; k < 26000; k++)
			dp[0][i][k] = dp[1][i][k] = 0;
	int m = 13000;
	dp[0][0][m + d[0][0]] = dp[0][0][m - d[0][0]] = 1;
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
			for (k = 0; k < 26000; k++)
				dp[1][j][k] = 0;
		for (j = 0; j < w; j++)
		{
			for (k = 0; k < 26000; k++)
			{
				if (dp[0][j][k] > 0)
				{
					if (i < h - 1)
						dp[1][j][k + d[i + 1][j]] = dp[1][j][k - d[i + 1][j]] = 1;
					if (j < w - 1)
						dp[0][j + 1][k + d[i][j + 1]] = dp[0][j + 1][k - d[i][j + 1]] = 1;
				}
			}
		}
		if (i < h - 1)
			for (j = 0; j < w; j++)
				for (k = 0; k < 26000; k++)
					dp[0][j][k] = dp[1][j][k];
	}
	int ans = 1000000009;
	for (k = 0; k < 26000; k++)
	{
		if (dp[0][w - 1][k] > 0)
		{
			if (k > m)
			{
				if (ans > k - m)
					ans = k - m;
			}
			else
			{
				if (ans > m - k)
					ans = m - k;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
