#include <stdio.h>

#define N 50

int main() {
	static char s[N][N + 1], t[N][N + 1];
	int n, m, i, j, k, l, yes;

	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%s", s[i]);
	for (i = 0; i < m; i++)
		scanf("%s", t[i]);
	for (i = 0; i + m <= n; i++)
		for (j = 0; j + m <= n; j++) {
			yes = 1;
			for (k = 0; k < m; k++)
				for (l = 0; l < m; l++)
					if (s[i + k][j + l] != t[k][l]) {
						yes = 0;
						goto out;
					}
out:
			if (yes) {
				printf("Yes\n");
				return 0;
			}
		}
	printf("No\n");
	return 0;
}
