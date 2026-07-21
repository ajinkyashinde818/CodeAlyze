#include <stdio.h>

#define N 200000

int main() {
	static int link1[N], link2[N];
	int n, m, i;

	scanf("%d%d", &n, &m);
	while (m--) {
		int a, b;

		scanf("%d%d", &a, &b), a--, b--;
		if (a == 0)
			link1[b] = 1;
		if (b == n - 1)
			link2[a] = 1;
	}
	for (i = 1; i < n - 1; i++)
		if (link1[i] && link2[i]) {
			printf("POSSIBLE\n");
			return 0;
		}
	printf("IMPOSSIBLE\n");
	return 0;
}
