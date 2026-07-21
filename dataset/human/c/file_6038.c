#include <stdio.h>
#include <stdlib.h>
int main() {
	int i;

	int n;
	int* Rt;
	int dif, maxProfit = -1000000000;
	int min;

	do {
		scanf("%d", &n);
	} while (n < 2 || 200000 < n);

	Rt = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		scanf("%d", &Rt[i]);
	}

	min = Rt[0];

	for (i = 1; i < n; i++) {
		dif = Rt[i] - min;
		if (maxProfit < dif) {
			maxProfit = dif;
		}
		if (Rt[i] < min) {
			min = Rt[i];
		}
	}

	printf("%d\n", maxProfit);

	return 0;
}
