#include <stdio.h>

typedef long long ll;

ll a[111111];

ll gcd(ll x, ll y) { return !y ? x : gcd(y, x % y); }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }

int main(void)
{
	ll n, m, i, LCM = 1;

	scanf("%lld %lld", &n, &m);
	for (i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
		a[i] /= 2;
		LCM = lcm(LCM, a[i]);

		if (LCM > m)
		{
			puts("0");
			return 0;
		}
	}

	for (i = 0; i < n; i++)
		if (!(LCM / a[i] % 2))
		{
			puts("0");
			return 0;
		}

	printf("%lld", m / LCM % 2 == 0 ? m / LCM / 2 : m / LCM / 2 + 1);
	return 0;
}
