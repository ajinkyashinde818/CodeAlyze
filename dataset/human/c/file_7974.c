#include <stdio.h>

#define MOD 1000000007

typedef long long ll;

ll fct[1333333] = { 1, 1 }, inv[1333333] = { 1, 1 }, fiv[1333333] = { 1, 1 };

ll combination(ll n, ll r)
{
	return fct[n] * fiv[r] % MOD * fiv[n - r] % MOD;
}

int main(void)
{
	ll X, Y, i;

	scanf("%lld %lld" ,&X, &Y);

	if ((X + Y) % 3)
	{
		puts("0");
		return 0;
	}

	ll x = (2 * Y - X) / 3, y = (2 * X - Y) / 3;

	if (x < 0 || y < 0)
	{
		puts("0");
		return 0;
	}

	for (i = 2; i <= x + y; i++)
	{
		fct[i] = fct[i - 1] * i % MOD;
		inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
		fiv[i] = fiv[i - 1] * inv[i] % MOD;
	}

    printf("%lld" ,combination(x + y, x));
    return 0;
}
