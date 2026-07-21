#include <stdio.h>
#define N 200000

int a[N] = { 0 };
int b[N] = { 0 };

int main(void) {
	int n, m;
	int x, y;

	scanf("%d %d", &n,&m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		if (x == 1) a[y]++;
		if (y == n) b[x]++;
	}
	for (int i = 1; i < n; i++) {
		if ((a[i] != 0) && (b[i] != 0)) {
			printf("POSSIBLE\n");
			return 0;
		}
	}
	printf("IMPOSSIBLE\n");

	return 0;
}
