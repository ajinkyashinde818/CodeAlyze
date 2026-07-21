#include <stdio.h>

int main()
{
	long a[200000];
	long b[200000];
	long x,y,i,n,m;
	scanf("%ld %ld", &n, &m);
	for (i = 0; i < m; i++) {
		a[i] = 0;
		b[i] = 0;
	}
	for (i = 0; i < m; i++) {
		scanf("%ld %ld", &x, &y);
		if (x == 1) {
			a[y-1] = 1;
		}
		if (y == n)
			b[x-1] = 1;
	}
	for (i = 0; i < m; i++) {
		if (a[i] == b[i]&&a[i] == 1) {
			printf("POSSIBLE");
			return 0;
		}
	}
	printf("IMPOSSIBLE");
	return 0;

}
