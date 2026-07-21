#include<stdio.h>
int gcd(long long  a, long long b)
{
	if (a > b)
	{
		while (b != 0)
		{
			long long temp = a % b;
			a = b;
			b = temp;
		}
		return a;
	}
	else
	{
		while (a != 0)
		{
			long long temp = b % a;
			b = a;
			a = temp;
		}
		return b;
	}
}
int main(void)
{
	long long a, b;
	scanf("%lld %lld", &a, &b);
	long long c = gcd(a, b);
	printf("%lld", c * (a / c) * (b / c));

	return 0;
}
