#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<assert.h>

typedef long long ll;
typedef unsigned long long ull;

int main()
{
	ll n;
	scanf("%lld", &n);
	if (n%2)
	{
		printf("0");
		return 0;
	}
	ll sum=0;
	for (ll i = 10; i <= n; i*=5)
	{
		sum += n / i;
	}
	printf("%lld",sum);
}
