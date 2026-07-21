#include <stdio.h>

int gcd(int a, int b)
{
	if (a > b) {
		a ^= b;
		b ^= a;
		a ^= b;
	}
	if (b % a == 0) return a;
	else return gcd(b % a, a);
}

int main()
{
	int A, B;
	scanf("%d %d", &A, &B);
	printf("%lld\n", (long long)A * B / gcd(A, B));
	fflush(stdout);
	return 0;
}
