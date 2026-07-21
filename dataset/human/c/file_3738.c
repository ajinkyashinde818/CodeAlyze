#include <stdio.h>

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

long long lcm(int a, int b) {
	return (long long) a * b / gcd(a, b);
}

int main() {
	int a, b;

	scanf("%d%d", &a, &b);
	printf("%lld\n", lcm(a, b));
	return 0;
}
