//AOJ ALDS1_1_D by bal4u
#include <stdio.h>

int main() {
	int n, c, max, min;

	scanf("%d", &n);
	int r[n];

	for (c = 0; c < n; c++) {
		scanf("%d", &r[c]);
	}

	max = r[1] - r[0],min = r[0];

	for (c = 0; c < (n - 1); c++) {
		if (((r[c+1] - min) >= 0) && ((r[c+1] - min) > max)) {
			max = r[c+1] - min;
		}else if (((r[c+1] - min) < 0) && (r[c+1] < min)) {
			min = r[c+1];
		}
	}

	printf("%d\n", max);

	return 0;
}
