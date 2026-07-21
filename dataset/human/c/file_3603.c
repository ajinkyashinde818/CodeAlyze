#include <stdio.h>
long long a, b;
long long gcd(long long gcd_a, long long gcd_b) {
	if (gcd_a < gcd_b) {
		long long gcd_c;
		gcd_c = gcd_a;
		gcd_a = gcd_b;
		gcd_b = gcd_c;
	}
	if (!gcd_b)return gcd_a;
	return gcd(gcd_b, gcd_a % gcd_b);
}
int main() {
	scanf("%lld%lld", &a, &b);
	b *= a / gcd(a, b);
	printf("%lld\n", b);
}
