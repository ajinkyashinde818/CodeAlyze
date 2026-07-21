#include <stdio.h>

int solve(int *b, int n, int w, int m)
{
	int v, i, p;

	p = 0;
	for (i = 0; i < m; i++){
		v = 0;
		while (p < n && v + b[p] <= w){
			v += b[p];
			p++;
		}
		if (p == n) return (1);
	}
	return (0);
}

int main(void)
{
	int books[128];
	int n, m;
	int f, l;
	int ans;
	int i;

	while (scanf("%d %d", &m, &n), m){
		for (i = 0; i < n; i++){
			scanf("%d", books + i);
		}

		f = 0;
		l = 1500000;
		while (f != l){
			int v = f + l >> 1;
			if (solve(books, n, v, m)){
				ans = v;
				l = v;
			}
			else f = v + 1;
		}
		printf("%d\n", ans);
	}
	return (0);
}
