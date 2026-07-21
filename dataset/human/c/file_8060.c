#include <stdio.h>

long long gcd(long long a, long long b)
{
	if (a > b) {
		a += b;
		b = a - b;
		a -= b;
	}
	if (b % a == 0) return a;
	else return gcd(b % a, a);
}

int main()
{	
	int i, T;
	long long A, B, C, D, G;
	scanf("%d", &T);
	
	for (i = 1; i <= T; i++) {
		scanf("%lld %lld %lld %lld", &A, &B, &C, &D);
		if (A < B || D < B) {
			printf("No\n");
			continue;
		} else if (C >= B - 1) {
			printf("Yes\n");
			continue;
		}
		
		A %= B;
		C %= B;
		G = gcd(B, D);
		if (A + (B - A - 1) / G * G > C) printf("No\n");
		else printf("Yes\n");
	}
	
	fflush(stdout);
	return 0;
}
