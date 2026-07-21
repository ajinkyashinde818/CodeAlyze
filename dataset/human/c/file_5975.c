#include <stdio.h>
#define X 10000000

int main() {
	int n, r[X], i, j, max=-2000000000, min;
	scanf("%d", &n);
	scanf("%d", &r[0]);
	min = r[0];
	for (i = 1; i < n; i++) {
		scanf("%d", &r[i]);
		if (min>r[i-1]) {
			min = r[i-1];
		}
		if (max<(r[i]-min)) {
			max = r[i] - min;
		}
	}
	printf("%d\n", max);
	return 0;
}
