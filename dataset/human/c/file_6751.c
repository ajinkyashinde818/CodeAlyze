// Aizu Vol-5 0545: Party
// 2017.8.31 bal4u@uu

#include <stdio.h>
#include <string.h>

typedef struct { int a, b; } T;
T r[10003]; int w;
char f[503];

int main()
{
	int n, m, a, b, i, ans;

	while (scanf("%d%d", &n, &m) && n) {
		memset(f, 0, n+1);
		for (w = 0, i = 0; i < m; i++) {
			scanf("%d%d", &a, &b);
			if (a == 1 || b == 1) f[a] = f[b] = 1;
			else r[w].a = a, r[w++].b = b;
		}
		for (i = 0; i < w; i++) {
			a = r[i].a, b = r[i].b;
			if (f[a] == 1 && f[b] == 1) continue;
			if (f[a] == 1) f[b] = 2;
			else if (f[b] == 1) f[a] = 2;
		}
		for (ans = 0, i = 2; i <= n; i++) if (f[i]) ans++;
		printf("%d\n", ans);
	}
	return 0;
}
