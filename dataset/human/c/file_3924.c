#include<stdio.h>
#include<stdlib.h>


int main() {
	int i, j, k, f = 0, n, s, t;
	int mp = 0, a, b, c, d, e, x, y, z;
	int g[50];
	d = 1;

	scanf("%d %d %d", &a, &b, &k);

	for (i = 1;i<101;i++) {
		if (a%i == 0&& b%i == 0) {
				g[d] = i;
				d++;
		}

	}


	e = d;
	x = d - k;

	printf("%d", g[x]);
	return 0;
}
