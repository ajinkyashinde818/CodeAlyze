#include <stdio.h>          // printf(), scanf()
#include <stdbool.h>

#define MAX_N 1000
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

char G[MAX_N][MAX_N + 1];
int dp[MAX_N][MAX_N];
int n;

int
square()
{
	int i, j;

	int max_n = 0;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			dp[i][j] = (G[i][j] == '.') ? 1 : 0;
			max_n |= dp[i][j];
		}
	}

	for (i = 1; i < n; ++i)
	{
		for (j = 1; j < n; ++j)
		{
			if (G[i][j] == '*')
				dp[i][j] = 0;
			else
			{
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
				max_n = max(max_n, dp[i][j]);
			}
		}
	}

	return max_n;
}

int
main(int argc, char **argv)
{
	int i;

	while (true)
	{
		scanf("%d\n", &n);
		if (n == 0)
			break;

		for (i = 0; i < n; ++i)
			fgets(&G[i][0], n + 2, stdin);

		printf("%d\n", square());
	}

	return 0;
}
