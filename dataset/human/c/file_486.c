#include <stdio.h>

long long int a[200000] = { 0 };

int main(void) {
	int N;
	long long int sum = 0, x = 0, ans = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &a[i]);
		sum += a[i];
	}

	for (int i = 0; i < N - 1; i++) {
		x += a[i];
		long long int rem = sum - 2 * x;
		if (i == 0) {
			if (rem >= 0) ans = rem;
			else ans = -rem;
		}
		else {
			if (rem >= 0) {
				if (rem < ans) ans = rem;
			}
			else {
				if (-rem < ans) ans = -rem;
			}
		}
	}

	printf("%lld\n", ans);

	return 0;
}
