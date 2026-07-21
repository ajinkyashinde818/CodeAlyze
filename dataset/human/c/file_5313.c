#include <stdio.h>

int c[22], a[22][22];

int main(void)
{
	int n, m, x, i, j, l, ans = 0x7fffffff;

	scanf("%d %d %d", &n, &m, &x);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &c[i]);
		for (j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	}

	int k[22];
	for (i = 0; i < (1 << n); i++)
	{
		int tmp = i;
		for (j = 1; j <= n; j++)
		{
			k[j] = tmp & 1;
			tmp >>= 1;
		}

		int t[22] = { 0 }, sum = 0;
		for (j = 1; j <= n; j++)
			if (k[j])
			{
				for (l = 1; l <= m; l++)
					t[l] += a[j][l];
				sum += c[j];
			}

		int cnt = 0;
		for (j = 1; j <= m; j++)
			if (t[j] >= x)
				++cnt;

		if (cnt == m)
		{
			if (ans > sum)
				ans = sum;
		}
	}

	if (ans == 0x7fffffff)
		puts("-1");
	else
		printf("%d", ans);
	return 0;
}
