//Snack
#include <stdio.h>
#include <limits.h>

long long gcd(long long x, long long y);

int main(void){
	long long A, B;
	scanf("%llu %llu", &A, &B);

	printf("%llu\n", A*B/gcd(A, B));

	return 0;
}

long long gcd(long long x, long long y) {
	long r;
	while((r = x % y) != 0) {
		x = y;
		y = r;
	}
	return y;
}
