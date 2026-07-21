#include <stdio.h>

long long mod = 1000000007;

long long f (long long a, long long b)
{
	long long result = 1;
	
	while (b > 0)
	{
		if (b % 2)
		{
			result *= a;
			result %= mod;
		}
		
		a *= a;
		a %= mod;
		b /= 2;
	}
	
	return result;
}

int main() {
	
	long long a = 1, b = 1, bi = 1;
	long long x, y, xx, yy, cntx = 0, cnty = 0, flag = 0, i;
	
	scanf("%lld %lld", &x, &y);
	
	if ((x + y) % 3 != 0)
		flag = -1;
	
	xx = (2 * x - y) / 3;
	yy = (2 * y - x) / 3;
	
	if (xx < 0 || yy < 0)
		flag = -1;
	
	
	if (flag == -1)
	{
		printf("0\n");
		
		return 0;
	}
	
	for (i = 1; i <= xx + yy; i++)
		a = (a * i) % mod;
	
	for (i = 1; i <= xx; i++)
		b = (b * i) % mod;
	
	for (i = 1; i <= yy; i++)
		b = (b * i) % mod;
	
	bi = f(b, mod - 2);
	
	printf("%lld", (a * bi) % mod);
	
	return 0;
}
