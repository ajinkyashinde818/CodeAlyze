#include <stdio.h>
#include <stdlib.h>
typedef long long ll;
int cmpint(const void *x, const void *y) {
	return *(int *)y - *(int *)x;
}
int main() {
	int n, a[300000];
	ll sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < 3 * n; i++) {
		scanf("%d", &a[i]);
	}
	qsort(a, n * 3, sizeof(int), cmpint);
	for (int i = 1; i < 2 * n; i += 2) {
		sum += a[i];
	}
	printf("%lld\n", sum);
	return 0;
}
