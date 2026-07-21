// AOJ 0224: Bicycle Diet
// 2017.10.27 bal4u@uu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 0x77777777
int c[7];
int g[110][110], a[110][64];
int m, N;

int id(char *s)
{
	if (*s == 'H') return 0;
	if (*s == 'D') return N-1;
	if (*s == 'C') return atoi(s+1);
	return atoi(s+1) + m;
}

int bellman()
{
	int i, j, u, v, chg, lim, ans;

	memset(a, INF, sizeof(a));
	a[0][0] = 0;
	lim = 1 << m;
	for (i = 0; i < N*lim; i++) {
		chg = 0;
		for (u = 0; u < N; u++) for (v = 0; v < N; v++) {
			if (u == v || g[u][v] == INF) continue;
			for (j = 0; j < lim; j++) {
				if (1 <= v && v <= m && (j & (1<<(v-1)))) continue;
				if (1 <= v && v <= m) {
					if (a[u][j] + g[u][v] - c[v] < a[v][j|(1<<(v-1))]) {
						a[v][j|(1<<(v-1))] = a[u][j] + g[u][v] - c[v];
						chg = 1;
					}
				} else {
					if (a[u][j] + g[u][v] < a[v][j]) {
						a[v][j] = a[u][j] + g[u][v];
						chg = 1;
					}
				}
			}
		}
		if (!chg) break;
	}
	ans = INF;
	for (i = 0; i < lim; i++) if (a[N-1][i] < ans) ans = a[N-1][i];
	return ans;
}

int main()
{
	int n, k, d, i;

	while (scanf("%d%d%d%d", &m, &n, &k, &d) && m > 0) {
		N = 2 + m + n;
		for (i = 1; i <= m; i++) scanf("%d", c+i);
		memset(g, INF, sizeof(g));

		for (i = 0; i < d; i++) {
			char b1[10], b2[10]; int s, t, e;
			scanf("%s%s%d", b1, b2, &e);
			s = id(b1), t = id(b2);
			if (k * e < g[s][t]) g[s][t] = g[t][s] = k * e;
		}
		printf("%d\n", bellman());
	}
	return 0;
}
