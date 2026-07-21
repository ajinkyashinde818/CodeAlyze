#include<stdio.h>
int main()
{
	int h, w, k;
	scanf("%d %d %d", &h, &w, &k);
	int i, j;
	char s[302][302];
	for (i = 0; i < h; i++)
		scanf("%s", s[i]);
	int ans[302][302];
	for (i = 0; i < h; i++)
		for (j = 0; j < w; j++)
			ans[i][j] = 0;
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			if (s[i][j] == '#')
			{
				ans[i][j] = k;
				k--;
			}
		}
	}
	for (i = 0; i < h; i++)
		for (j = 0; j < w - 1; j++)
			if (ans[i][j + 1] == 0)
				ans[i][j + 1] = ans[i][j];
	for (i = 0; i < h; i++)
		for (j = w - 1; j > 0; j--)
			if (ans[i][j - 1] == 0)
				ans[i][j - 1] = ans[i][j];
	for (j = 0; j < w; j++)
		for (i = 0; i < h - 1; i++)
			if (ans[i + 1][j] == 0)
				ans[i + 1][j] = ans[i][j];
	for (j = 0; j < w; j++)
		for (i = h - 1; i > 0; i--)
			if (ans[i - 1][j] == 0)
				ans[i - 1][j] = ans[i][j];
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w - 1; j++)
			printf("%d ", ans[i][j]);
		printf("%d\n", ans[i][w - 1]);
	}
	return 0;
}
