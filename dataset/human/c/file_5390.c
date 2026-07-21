#include<stdio.h>
int main()
{
	int n, m, x;
	scanf("%d %d %d", &n, &m, &x);
	int c[20], a[20][20];
	int i, j, k, l;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &c[i]);
		for (j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	}
	int max = 1;
	for (i = 0; i < n; i++)
		max *= 2;
	int b[20];
	int res, ans = -1;
	for (k = 0; k < max; k++)
	{
		for (i = 0; i < m; i++)
			b[i] = 0;
		l = k;
		res = 0;
		for (i = 0; i < n; i++)
		{
			if (l % 2 > 0)
			{
				res += c[i];
				for (j = 0; j < m; j++)
					b[j] += a[i][j];
			}
			l /= 2;
		}
		if (res == 1067)
		{
			res++;
			res--;
		}
		for (i = 0; i < m; i++)
			if (b[i] < x)
				res = -1;
		if (res >= 0)
		{
			if (ans<0 || ans>res)
				ans = res;
		}
	}
	printf("%d\n", ans);
	return 0;
}
