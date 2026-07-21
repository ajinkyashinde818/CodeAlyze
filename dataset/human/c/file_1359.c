#include <stdio.h>

int aaa[200000] = {};

int main()
{
	long n, m;
	long x, y;
	int ans = 0;
	scanf("%ld %ld", &n, &m);
	for (long i = 0; i < m; i++)
	{
		scanf("%ld %ld", &x,&y);
		if (x == 1)
		{
			aaa[y]++;
		}
		if (y == n)
		{
			aaa[x]++;
		}
	}
	for (long i = 0; i < 200000; i++)
	{
		if (aaa[i] >= 2)
		{
			ans = 1;
			break;
		}
	}
	if (ans == 1)
	{
		printf("POSSIBLE");
	}
	else
	{
		printf("IMPOSSIBLE");
	}
	return 0;
}
