#include<stdio.h>
#include<stdlib.h>

long long int gcd(long long int a, long long int b) {
	long long int r;
	while (b!=0) {
		r = a % b;
			a = b;
			b = r;
	}
	return a;
}

int main(void)
{
    long long int a,b,g;
	scanf("%lld %lld", &a, &b);
	g = gcd(a, b);

	printf("%lld\n", (a * b) / g);
	return 0;
}
