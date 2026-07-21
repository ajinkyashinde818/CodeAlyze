// Aizu 2205: Lottery Checker
// 2017.9.20 bal4u@uu

#include <stdio.h>

char k[102][10];
int v[102];

int main()
{
	int n, m, i, j, ans;
	char a[10];

	while (scanf("%d%d", &n, &m) && n) {
		for (i = 0; i < n; i++) scanf("%s%d", k[i], v+i);
		ans = 0; while (m-- > 0) {
			scanf("%s", a);
			for (i = 0; i < n; i++) {
				for (j = 0; j < 8; j++) if (k[i][j] != '*' && k[i][j] != a[j]) break;
				if (j == 8) { ans += v[i]; break; }
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
