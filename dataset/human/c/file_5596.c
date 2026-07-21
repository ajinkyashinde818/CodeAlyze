#include <stdio.h>

long long int x;
long long ans;

int main(void)
{
	scanf("%lld", &x);
	// (x / (6 + 5) + 1) * 2
	if (x % (6 + 5) != 0)
	{
		if ((6 + 5)*(x / (6 + 5)+1) >= x + 5)
		{
			printf("%lld\n", (x / (6 + 5)+1) * 2 - 1);
		}
		else
		{
			printf("%lld\n", (x / (6 + 5)+1) * 2);
		}
	}
	else
	{
		if ((6 + 5)*(x / (6 + 5)) >= x + 5)
		{
			printf("%lld\n", (x / (6 + 5)) * 2 - 1);
		}
		else
		{
			printf("%lld\n", (x / (6 + 5)) * 2);
		}
	}
	return 0;
}
