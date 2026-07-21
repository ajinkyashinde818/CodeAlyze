#include <stdio.h>

#define N 20

int main() {
	static int aa[N], bb[N], cc[N];
	int n, i, sum;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &aa[i]), aa[i]--;
	for (i = 0; i < n; i++)
		scanf("%d", &bb[i]);
	for (i = 0; i < n - 1; i++)
		scanf("%d", &cc[i]);
	sum = 0;
	for (i = 0; i < n; i++) {
		sum += bb[aa[i]];
		if (i > 0 && aa[i - 1] == aa[i] - 1)
			sum += cc[aa[i - 1]];
	}
	printf("%d\n", sum);
	return 0;
}
