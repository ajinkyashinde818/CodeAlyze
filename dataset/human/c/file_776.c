#include <stdio.h>
#include <math.h>

int max(int a, int b) {
	return a > b ? a : b;
}

int min(int a, int b) {
	return a < b ? a : b;
}

int f[15][1000] = {};

int main() {
	int d, g;

	int p[15], c[15];



	scanf("%d%d", &d, &g);

	g /= 100;

	int i;
	for (i = 0; i < d; i++) {
		scanf("%d%d", &p[i], &c[i]);
		c[i] /= 100;
	}

	int j;
	int m = 1000000;
	for (i = 0; i < (1 << d); i++) {
		int num = 0, nmax = -1, sum = 0;
		for (j = 0; j < d; j++) {
			if ((i >> j) & 1) {
				num += p[j];
				sum += p[j] * (j+1) + c[j];
			}
			else {
				nmax = j;
			}
		}

		if (g > sum&&nmax == -1) continue;

		if (g > sum) {
			int need = ceil((double)(g - sum) / (double)(nmax+1));

			if (need > p[nmax] && (sum + p[nmax] * nmax + c[nmax]) < g) continue; else if (need >p[nmax]) need = p[nmax];

			num += need;
		}

		m = min(m, num);
	}

	printf("%d", m);
	getchar(); getchar();
}
