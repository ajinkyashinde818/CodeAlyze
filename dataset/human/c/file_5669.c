#include <stdio.h>
#include <stdlib.h>

int main() {

	int n, t, i, min, max_profit;

	int *Rt;
	
	scanf("%d", &n);
	Rt = (int *)malloc(sizeof(int) * n);
	if (Rt == NULL) exit(0);

	for (t = 0; t < n; t++) {
		scanf("%d", &Rt[t]);
	}

	for (t = 0; t < n - 1; t++) {
		if (t == 0 || min > Rt[t]) {
			min = Rt[t];
			for (i = t + 1; i < n; i++) {
				if ((t == 0 && i == 1) || Rt[i] - Rt[t] > max_profit) {
					max_profit = Rt[i] - Rt[t];
				}
			}
		}
	}

	printf("%d\n", max_profit);

	free(Rt);
	return 0;

}
