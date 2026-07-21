#include <stdio.h>
int dp[1010][1010];
typedef long long ll;
ll M = 1000000007;
int f(int n, int k)
{
	if (dp[n][k]) return dp[n][k];
	if (n == k) return 1;
	if (k == 0) return 1;
	if(n<=1000&&k<=1000) return dp[n][k]=f(n - 1, k - 1) + f(n - 1, k);
	else return f(n - 1, k - 1) + f(n - 1, k);
}
ll pow2(long long base, int index, int mod) {
	if (index == 1) return base;
	if (index % 2 == 0) {
		long long r = pow2(base, index / 2, mod);
		return (r * r) % mod;
	}
	else {
		return (base * pow2(base, index - 1, mod)) % mod;
	}
}

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	int a, b;
	a = (2 * y - x) / 3;
	b = (2 * x - y) / 3;
	ll A=1;
	ll B = 1;
	if ((2 * x - y) % 3 == 0 && (2 * y - x) % 3 == 0 && (2 * y - x) >= 0 && (2 * x - y) >= 0)
	{
		for (ll i = a + b; i >= 1; i--)
		{
			A *= i;
			A %= M;
		}
		for (ll i = a; i >= 1; i--)
		{
			B *= i;
			B %= M;
		}
		for (ll i = b; i >= 1; i--)
		{
			B *= i;
			B %= M;
		}
		B=pow2(B, M - 2, M);
		printf("%lld", (A*B)%M);
	}
	else
	{
		printf("0");
	}
}
