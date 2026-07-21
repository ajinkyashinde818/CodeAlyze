#include <stdio.h>

int zettaiti(int x) {
	return x >= 0 ? x : -x;
}

int main(void) {
	int n, m;
	int a, b, c, d;
	int as = 0, bs = 0, cs = 0, ds = 0, ss = -1;
	int heikin, chuuou, score;
	int i;
	if (scanf("%d%d", &n, &m) != 2) return 1;
	if (n == 1) {
		printf("%d\n", m);
	} else if (n == 2) {
		printf("%d %d\n", m, m);
	} else if (n % 2 != 0) {
		for (a = 0; a <= m; a++) {
			for (b = a; b <= m; b++) {
				for (c = b; c <= m; c++) {
					heikin = a * (n / 2) + b + c * (n / 2);
					chuuou = b * n;
					score = zettaiti(heikin - chuuou);
					if (score > ss) {
						as = a;
						bs = b;
						cs = c;
						ss = score;
					}
				}
			}
		}
		for (i = 0; i < n / 2; i++) printf("%d ", as);
		printf("%d", bs);
		for (i = 0; i < n / 2; i++) printf(" %d", cs);
		putchar('\n');
	} else {
		for (a = 0; a <= m; a++) {
			for (b = a; b <= m; b++) {
				for (c = b; c <= m; c++) {
					for (d = c; d <= m; d++) {
					heikin = (a * (n / 2 - 1) + b + c + d * (n / 2 - 1)) * 2;
					chuuou = (b + c) * n;
					score = zettaiti(heikin - chuuou);
					if (score > ss) {
						as = a;
						bs = b;
						cs = c;
						ds = d;
						ss = score;
					}
					}
				}
			}
		}
		for (i = 0; i < n / 2 - 1; i++) printf("%d ", as);
		printf("%d %d", bs, cs);
		for (i = 0; i < n / 2 - 1; i++) printf(" %d", ds);
		putchar('\n');
	}
	return 0;
}
