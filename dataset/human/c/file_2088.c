#include<stdio.h>
#include<string.h>
int main()
{
	char s[1000006];
	scanf("%s", s);
	int i, n = strlen(s);
	long long int ans = 0;
	long long int a[1000006];
	for (i = 0; i < n; i++)
		a[i] = (long long int)(s[i] - '0');
	for (i = n - 1; i > 0; i--)
	{
		if (a[i] > 9)
		{
			a[i - 1]++;
			a[i] %= 10;
		}
		if (a[i] > 5)
		{
			a[i - 1]++;
			ans += 10 - a[i];
		}
		else if (a[i] == 5 && a[i - 1] >= 5)
		{
			a[i - 1]++;
			ans += 5;
		}
		else
			ans += a[i];
	}
	while (a[0] > 0)
	{
		if (a[0] % 10 > 5)
		{
			ans += 10 - a[0] % 10;
			a[0] = a[0] / 10 + 1;
		}
		else if (a[0] == 5 && a[0] / 10 % 10 >= 5)
		{
			ans += 5;
			a[0] = a[0] / 10 + 1;
		}
		else
		{
			ans += a[0] % 10;
			a[0] /= 10;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
