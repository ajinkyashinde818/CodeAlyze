#include <stdlib.h>
#include <stdio.h>

int D, G, p[10], c[10];

void solve();

int main() {
	int i;
	scanf("%d%d", &D, &G);
	for (i = 0; i < D; i++) scanf("%d%d", &p[i], &c[i]);
	solve();
	return 0;
}

void solve() {
	int i, j, k, max_score[12][1010], temp[110], cnt, t;
	for (i = 0; i < 12; i++)for (j = 0; j < 1010; j++)max_score[i][j] = 0;

	cnt = 0;
	for (j = 0; j < D; j++) {
		for (i = 0; i <= p[j]; i++) temp[i] = i * (j + 1) * 100;
		temp[p[j]] += c[j];

		for (i = 0; i <= cnt; i++) {
			for (k = 0; k <= p[j]; k++) {
				t = max_score[j][i] + temp[k];
				if (max_score[j + 1][i + k] < t) max_score[j + 1][i + k] = t;
			}
		}
		cnt += p[j];
	}

	for (i = 1; i <= cnt; i++) if (max_score[D][i] >= G) {
		printf("%d\n", i);
		break;
	}
}
