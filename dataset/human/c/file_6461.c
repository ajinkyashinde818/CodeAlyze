#include <stdio.h>

#define N 200000

int main() {
	int n, i, max, min;
	int R[N];

	scanf("%d", &n);

	scanf("%d", &R[0]);

	min = R[0];
	max = -1e9;

	for (i = 1; i < n; i++) {
		scanf("%d", &R[i]);
		if (max < R[i] - min) max = R[i] - min;
		if (R[i] < min) min = R[i];
	}

	printf("%d\n", max);

	return 0;
}
