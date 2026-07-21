#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<assert.h>

typedef long long ll;
typedef unsigned long long ull;

ll gcd(ll a, ll b) {
	if (a % b) { return gcd(b, a % b); }
	return b;
}

int main()
{
	ll a, b;
	scanf("%lld%lld", &a, &b);
	printf("%lld", a * b / gcd(a, b));
}
