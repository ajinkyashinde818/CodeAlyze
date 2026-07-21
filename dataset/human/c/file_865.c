#include<stdio.h>
#include<math.h>

int main() {
	long long n;
	int ans = 0;
	scanf("%lld", &n);

	for (int i = 2; i <= sqrt(n); i++) {
		long long pow = i;
		while (n%pow==0) {
			n /= pow;
			ans++;
			pow *= i;
		}
		while (n % i == 0) {
			n /= i;
		}
	}
	if (n != 1) ans++;

	printf("%d", ans);

	return 0;
}
