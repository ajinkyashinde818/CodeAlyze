#include <stdio.h>
long long lcm(long long a, long long b)
{
	long long remain;
	long long ta = a, tb = b;
	while (1)
	{
		remain = ta % tb;
		if (!remain) break;
		ta = tb, tb = remain;
	}
	return a * b / tb;
}
int main(void)
{
	long long a, b;
	if (scanf("%lld %lld", &a, &b) == 2) printf("%lld", lcm(a, b));
}
