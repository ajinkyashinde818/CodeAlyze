#include <stdio.h>

int main(int argc, char const *argv[]) {
	int n, i, j, max = -1000000000, min;
	int a[200000];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
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
