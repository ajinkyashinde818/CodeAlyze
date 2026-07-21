#include <stdio.h>

int main() {
	int i, n, min, maxdif, a[200000];
	maxdif = -1000000000;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	min = a[0];

	for (i = 1; i < n; i++) {
		if (maxdif < a[i] - min) { maxdif = a[i] - min; }
		if (a[i] < min) { min = a[i]; }
	}

	printf("%d\n", maxdif);

	return 0;
}
