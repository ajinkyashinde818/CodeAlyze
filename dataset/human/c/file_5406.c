#include<stdio.h>
#include<math.h>

int main() {
	int n, m, x, i, j, k;
	int c[12], a[12][12];
	//入力
	scanf("%d %d %d", &n, &m, &x);
	for (i = 0; i < n; i++) {
		scanf("%d", &c[i]);
		for (j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	int minC = 1200000, flag1 = 0;
	for (i = 1; i <= pow(2, n) - 1; i++) {
		int sumC = 0, flag2 = 0;
		int sumA[12] = {};
		for (j = 0; j < n; j++) {
			int mask = pow(2, j);
			if (i & mask) {
				sumC += c[j];
				for (k = 0; k < m; k++) {
					sumA[k] += a[j][k];
				}
			}
		}
		for (j = 0; j < m; j++) {
			if (sumA[j] >= x) flag2++;
		}
		if (flag2 == m && minC >= sumC) {
			minC = sumC;
			flag1 = 1;
		}
	}
	if (flag1 == 0) printf("-1");
	else printf("%d", minC);

	return 0;
}
