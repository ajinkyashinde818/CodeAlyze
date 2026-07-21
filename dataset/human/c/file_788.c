#include <stdio.h>
#include <math.h>
#include <string.h>

int mini(int a, int b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}

int main() {
	int D, i, p[10], c[10], G, min = 1000, sum, count, complete[10], j, rem, quo;

	scanf("%d %d", &D, &G);
	for (i = 0; i < D; i++) {
		scanf("%d %d", &p[i], &c[i]);
	}

	for (i = 0; i < pow(2, D); i++) {
		sum = 0;
		count = 0;
		for (j = 0; j < D; j++) {
			if ((i >> j) % 2 == 1) {
				sum = sum + c[j] + (j + 1) * 100 * p[j];
				count = count + p[j];
				complete[j] = 1;
			}
			else {
				complete[j] = 0;
			}
		}
		if (sum < G) {
			for (j = D - 1; j >= 0; j--) {
				if (complete[j] == 0) {
					if (G <= sum + (j + 1) * 100 * (p[j] - 1)) {
						rem = (G - sum) % ((j + 1) * 100);
						quo = (G - sum) / ((j + 1) * 100);
						if (rem == 0) {
							count = count + quo;
							sum = sum + (j + 1) * 100 * quo;
						}
						else {
							count = count + quo + 1;
							sum = sum + (j + 1) * 100 * (quo + 1);
						}

					}
					break;
				}
			}
		}
		if (sum >= G) {
			min = mini(min, count);
		}
	}

	printf("%d", min);

	return 0;
}
