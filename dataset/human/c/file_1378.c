#include <stdio.h>

int g[2][200005];

int main()
{
	int n, m;
	int a, b;
	int f = 0;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		
		if (a == 1) {
			g[0][b] = 1;
		} else if (b == n) {
			g[1][a]= 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (g[0][i] == 1 && g[1][i] == 1) {
			f = 1;
		}
	}

	if (f) {
		puts("POSSIBLE");
	} else {
		puts("IMPOSSIBLE");
	}

	return 0;
}
