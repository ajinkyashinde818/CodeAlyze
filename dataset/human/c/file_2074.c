// Aizu Vol-1 0181: Bookshelf

#include <stdio.h>
#include <string.h>

#define INF 0x7fffffff
#define MAX(a,b) ((a)>=(b)?(a):(b))
int c[22][102][102];
int w[102];

int main()
{
	int m, n, i, j, k, l;

	while (scanf("%d%d", &m, &n) && m) {
		memset(c, 0, sizeof(c));
		for (w[0] = k = 0, i = 1; i <= n; i++) {
			scanf("%d", &l), w[i] = w[i-1] + l;
			if (l > k) k = l;
		}
		if (n <= m) { printf("%d\n", k); continue; } 

		for (i = 1; i <= n; i++) c[1][1][i]= w[i];
		for (k = 2; k <= m; k++) {
			for (i = 1; i <= n; i++) for (j = i; j < n; j++) for (l = j; l < n; l++)
				if (c[k-1][i][j] > 0) {
					int t = MAX(w[l+1]-w[j], c[k-1][i][j]);
					if (c[k][j+1][l+1] == 0 || t < c[k][j+1][l+1]) c[k][j+1][l+1] = t;
				}
		}
		for (k = INF, i = 1; i <= n; i++)
			if (c[m][i][n] > 0 && c[m][i][n] < k) k = c[m][i][n];
		printf("%d\n", k);
	}
	return 0;
}
