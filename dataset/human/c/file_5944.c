#include<stdio.h>
#include<stdlib.h>

int main() {
	int n, max;
	int *data;
	int cmp,maxarray;
	int i, j, k;

	scanf("%d",&n);

	data = (int *)malloc(n * sizeof(int));

	for (i = 0; i < n; i++) {
		scanf("%d",&data[i]);
	}

	max = data[n - 1] - data[n - 2];
	maxarray = data[n - 1];

	for (i = n - 2; i > 0; i--) {
		if (data[i] > maxarray)
			maxarray = data[i];

		if (maxarray - data[i - 1] > max)
			max = maxarray - data[i - 1];
	}

	printf("%d\n", max);

	free(data);
	return 0;
}
