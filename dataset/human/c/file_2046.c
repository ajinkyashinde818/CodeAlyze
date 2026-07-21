#include <stdio.h>

typedef long long int lli;

int main()
{
	lli a, b, c, count = 0;

	scanf("%lld%lld%lld", &a, &b, &c);

	if (c <= a + b)
	{
		count = b + c;
	}

	else if (c > a + b)
	{
		count = 2 * b + a + 1;
	}

	printf("%lld\n", count);

	return 0;
}
