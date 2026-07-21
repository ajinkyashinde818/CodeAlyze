#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



int cmp(const void* a, const void* b) {
	return *(long*)b - *(long*)a;
}

int main(void) {
	long a[300000];
	long n, i;
	long long ans = 0;
	scanf("%ld", &n);
	for (i = 0; i < 3 * n; i++) {
		scanf("%ld", &a[i]);
	}
	qsort(a, 3 * n, sizeof(long), cmp);
	for (i = 0; i < n; i++) {
		ans += (long long)a[i * 2 + 1];
	}
	printf("%lld\n", ans);
	return 0;
}
