#include <stdbool.h>
#include <stdio.h>
int n, m, x, c[12], a[12][12] = {0};
int b[12];
int cost = 1e9;
void dfs(int bit, int len) {
	if (len == n) {
		int u[12] = {0};
		int co = 0;
		for (int i = 0; i < n; i++) {
			if (b[i]) {
				co += c[i];
				for (int j = 0; j < m; j++) {
					u[j] += a[i][j];
				}
			}
		}
		bool isOK = true;
		for (int i = 0; i < m; i++) {
			if (u[i] < x) {
				isOK = false;
				break;
			}
		}
		if (isOK && cost > co) {
			cost = co;
		}
		return;
	}
	b[len] = bit;
	for (int i = 0; i < 2; i++) {
		dfs(i, len + 1);
	}
	return;
}
int main() {
	scanf("%d%d%d", &n, &m, &x);
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	dfs(0, 0);
	dfs(1, 0);
	printf("%d\n", cost == (int)1e9 ? -1 : cost);
	return 0;
}
