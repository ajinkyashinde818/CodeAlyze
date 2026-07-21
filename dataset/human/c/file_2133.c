#include<stdio.h>
int main()
{
	long long int n;
	scanf("%lld", &n);
	if (n % 2 > 0)
		printf("0\n");
	else
	{
		long long int ans = 0, c = 5;
		n /= 2;
		while (n >= c)
		{
			ans += n / c;
			c *= 5;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
