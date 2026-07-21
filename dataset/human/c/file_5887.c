#include <stdio.h>

int main(void) {
	int n, t;
	int max, min;
	int a[200000];
	int i;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &t);
		a[i] = t;
	}

	max = a[1] - a[0];
	min = a[0];

	for (i = 1; i < n; i++) {
		if (max < a[i] - min) {
			max = a[i] - min;
		}
		if (min > a[i]) {
			min = a[i];
		}
	}

	printf("%d\n", max);
	return 0;
}
