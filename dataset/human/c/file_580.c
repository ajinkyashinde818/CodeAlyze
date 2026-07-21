#include <stdio.h>
int n, m, f, x;
char a[50][51];
char b[50][51];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf(" %s", a[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf(" %s", b[i]);
	}
	for (int i = 0; i <= n - m; i++) {
		for (int j = 0; j <= n - m; j++) {
			x = 1;
			for (int k = 0; k < m; k++) {
				for (int l = 0; l < m; l++) {
					if (a[i + k][j + l] != b[k][l])x = 0;
				}
			}
			if (x)f = 1;
		}
	}
	if (f)printf("Yes\n");
	else printf("No\n");
}
