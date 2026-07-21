#include <stdio.h>

#define N 100

int main() {
	static int aa[N];
	int n, d, x, i, j, sum;

	scanf("%d%d%d", &n, &d, &x);
	for (i = 0; i < n; i++)
		scanf("%d", &aa[i]);
	sum = 0;
	for (i = 0; i < n; i++) {
		int cnt;

		cnt = 0;
		for (j = 0; j < d; j += aa[i])
			cnt++;
		sum += cnt;
	}
	printf("%d\n", sum + x);
	return 0;
}
