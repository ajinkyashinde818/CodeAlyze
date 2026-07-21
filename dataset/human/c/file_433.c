#include <stdio.h>
long long n, x, ans = 1;
long long p = 1000000007;
char s[200005];
int a[200005];
int main() {
	scanf("%lld", &n);
	scanf(" %s", s);
	for (int i = 0; i < 2 * n; i++) {
		if (i % 2) {
			if (s[i] == 'W')a[i] = 0;
			else a[i] = 1;
		}
		else {
			if (s[i] == 'B')a[i] = 0;
			else a[i] = 1;
		}
	}
	for (int i = 0; i < 2 * n; i++) {
		if (a[i]) {
			ans *= x;
			ans %= p;
			x--;
		}
		else x++;
	}
	if (x != 0)ans = 0;
	for (long long i = 1; i <= n; i++) {
		ans *= i;
		ans %= p;
	}
	printf("%lld\n", ans);
}
