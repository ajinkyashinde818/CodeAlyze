#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, i, j, max, min;
	int *R;

	scanf("%d", &n);
	R = malloc(sizeof(int*) * n);

	for (i = 0; i < n; i++) {
		scanf("%d", R + i);
	}

	max = R[1] - R[0];
	if (R[0] < R[1]) min = R[0];
	else min = R[1];
	
	for (i = 2; i < n; i++) {
		if (max < R[i] - min) max = R[i] - min;
		if (min > R[i]) min = R[i];
	}

	printf("%d\n", max);

	return 0;
}
