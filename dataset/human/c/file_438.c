#include<stdio.h>
int main()
{
	long long int n;
	scanf("%lld\n", &n);
	char s[200005];
	scanf("%s", s);
	long long int p = 1e9 + 7;
	long long int i;
	long long int count = 0, ans = 1;
	for (i = 1; i <= n; i++)
		ans = ans * i % p;
	for (i = 0; i < 2 * n; i++)
	{
		if (s[i] == 'B')
		{
			if (count % 2 == 0)
				count++;
			else
			{
				ans = ans * count % p;
				count--;
			}
		}
		else
		{
			if (count % 2 == 1)
				count++;
			else
			{
				ans = ans * count % p;
				count--;
			}
		}
	}
	if (count != 0)
		ans = 0;
	printf("%lld\n", ans);
	return 0;
}
