#include<stdio.h>
int main(void) {

	long long n, r;
	long long ans;

	scanf("%lld %lld", &n, &r);

	if (n < 10) {
		ans = 100 * (10 - n) + r;
		printf("%lld", ans);
	}
	else if (n >= 10) {
		ans = r;
		printf("%lld", ans);
	}

	return 0;
}
