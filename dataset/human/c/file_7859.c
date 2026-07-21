// Aizu 1016: Fibonacci Sets
// 2017.9.17 bal4u@uu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int f[1005], a[1005];

int cmp(int *a, int *b) { return *a - *b; }

int main()
{
	int V, d, i, ans;

	f[0] = 2, f[1] = 3; for (i = 2; i <= 1000; i++) f[i] = (f[i-1] + f[i-2]) % 1001;
	while (scanf("%d%d", &V, &d) == 2) {
		memcpy(a, f, sizeof(int)*V);
		qsort(a, V, sizeof(int), cmp);
		for (ans = 1, i = 1; i < V; i++) if (a[i] - a[i-1] >= d) ans++;
		printf("%d\n", ans);
	}
	return 0;
}
