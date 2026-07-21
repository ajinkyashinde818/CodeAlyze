// Aizu Vol-6 0620: Swapping Bibs
// 2017.9.5 bal4u@uu

#include <stdio.h>

int a[102];

int main()
{
	int n, m, i, k, t;

	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) scanf("%d", a+i);
	for (k = 1; k <= m; k++) {
		for (i = 1; i < n; i++)
			if (a[i] % k > a[i+1] % k) t = a[i], a[i] = a[i+1], a[i+1] = t;
	}
	for (i = 1; i <= n; i++) printf("%d\n", a[i]);
	return 0;
}
