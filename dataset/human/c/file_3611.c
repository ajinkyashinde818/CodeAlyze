#include "stdio.h"
int main() {
	long a, b, ans;
	scanf("%lu%lu", &a, &b);
	ans = a * b;
 	long ii = a < b ? a : b;
	for (long i = a < b ? a : b; i >= 2; i--) {
		if (a % i == 0 && b % i == 0) {
			a /= i;
			b /= i;
			ans /= i;
		}
	}
	printf("%lu", ans);
}
