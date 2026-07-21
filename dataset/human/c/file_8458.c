#include<stdio.h>
int main() {
	int n,m,a[101],i,j,d;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n - 1; j++) {
			if (a[j] % i > a[j + 1] % i) {
				d = a[j];
				a[j] = a[j + 1];
				a[j + 1] = d;
			}
		}
	}
	for (i = 1; i <= n; i++)printf("%d\n", a[i]);
	return 0;
}
