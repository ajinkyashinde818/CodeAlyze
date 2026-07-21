#include<stdio.h>

int main() {
	int n, i, j;
	int R[200000];
	int max, min;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d", &R[i]);

	max = R[1] - R[0];
	min = R[0];

	for (j = 1; j < n; j++) {
		if (R[j] - min > max) max = R[j] - min;
		if (min > R[j]) min = R[j];
	}

	printf("%d\n", max);

	return 0;
}
