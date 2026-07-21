#include <stdio.h>

int main(void) {
	int n, i;
	int min_value;
	int max = 0;
	int R;
	if (scanf("%d", &n) != 1 || n < 2) return 1;
	if (scanf("%d", &min_value) != 1) return 1;
	if (scanf("%d", &R) != 1) return 1;
	max = R - min_value;
	if (min_value > R) min_value = R;
	for (i = 2; i < n; i++) {
		int R;
		if (scanf("%d", &R) != 1) return 1;
		if (max < R - min_value) max = R - min_value;
		if (min_value > R) min_value = R;
	}
	printf("%d\n", max);
	return 0;
}
