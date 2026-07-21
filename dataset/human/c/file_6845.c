#include <stdio.h>
#include <stdlib.h>

int N, a[300000];
long long int ans;

int comp(const void *p1, const void *p2) { return *(const int *)p1 - *(const int *)p2; }

int main(void) {
	int i, count;

	scanf("%d", &N);
	for (i = 0; i < 3 * N; i++) scanf("%d", &a[i]);
	qsort(a, N * 3, sizeof(int), comp);

	i = N * 3 - 1;
	count = 0;
	while (count < N) {
		ans += a[i - 1];
		i -= 2;
		count++;
	}

	printf("%lld\n", ans);
	return 0;
}
