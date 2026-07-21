#include <stdio.h>
int main() {
	int n, m, A, B, pt[200000] = {0};
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &A, &B);
		if (A == 1) {
			pt[B - 1]++;
		} else if (B == n) {
			pt[A - 1]++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (pt[i] >= 2) {
			printf("POSSIBLE\n");
			return 0;
		}
	}
	printf("IMPOSSIBLE\n");
	return 0;
}
