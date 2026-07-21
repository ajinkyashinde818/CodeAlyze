#include<stdio.h>
long long int gcd(long long int a, long long int b)
{
	long long int r = a % b;
	while (r > 0)
	{
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}
int main()
{
	long long int a, b;
	scanf("%lld %lld", &a, &b);
	printf("%lld\n", a / gcd(a, b) * b);
	return 0;
}
