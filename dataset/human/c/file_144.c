#include <stdio.h>

int r,g,b,n;

int main()
{
	long long ans = 0;
	scanf("%d %d %d %d", &r, &g, &b, &n);

	for (int i = 0;i <= n; i += r)
	{
		for (int j = 0; j + i <= n; j += g)
		{
			int temp = n - i - j;
			if (temp % b == 0)
				ans++;
		}
	}

	printf("%lld", ans);

	return 0;
}
