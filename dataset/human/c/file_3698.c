#include <stdio.h>
#include <string.h>
#include <math.h>

long gcd(long x, long  y) {
	if (x < y) {
		long tmp = x;
		x = y;
		y = tmp;
	}
	if (x % y == 0)return y;
	else
	{
		gcd(y, x % y);
	}
}

int main(void) {
	long a, b;
	scanf("%ld %ld", &a, &b);
	printf("%ld", a*b/gcd(a, b));


	return 0;
}
