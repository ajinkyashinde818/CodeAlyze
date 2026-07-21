#include <stdbool.h>
#include <stdio.h>
#include <string.h>
int main() {
	int n, m;
	char a[50][50], b[50][50];
	bool isInclude;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", a[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%s", b[i]);
	}
	for (int i = 0; i <= n - m; i++) {
		for (int j = 0; j <= n - m; j++) {
			isInclude = true;
			for (int k = 0; k < m; k++) {
				for (int l = 0; l < m; l++) {
					if (a[i + k][j + l] != b[k][l]) {
						isInclude = false;
					}
				}
			}
			if (isInclude) {
				printf("Yes\n");
				return 0;
			}
		}
	}
	printf("No\n");
	return 0;
}
