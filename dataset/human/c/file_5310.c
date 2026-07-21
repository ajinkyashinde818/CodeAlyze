#include <stdio.h>
int n, m, x, t, e, o, f, ans;
int c[12];
int b[12];
int y[12];
int a[12][12];
int main() {
	scanf("%d%d%d", &n, &m, &x);
	t = 1;
	ans = 2000000;
	for (int i = 0; i < n; i++) {
		scanf("%d", c + i);
		for (int j = 0; j < m; j++) {
			scanf("%d", a[i] + j);
		}
		t *= 2;
	}
	for (int i = 0; i < t; i++) {
		e = i;
		o = 0;
		for (int j = 0; j < n; j++) {
			b[j] = e % 2;
			e /= 2;
			if (b[j])o += c[j];
		}
		for (int j = 0; j < m; j++) {
			y[j] = 0;
		}
		for (int j = 0; j < n; j++) {
			if (b[j]) {
				for (int k = 0; k < m; k++) {
					y[k] += a[j][k];
				}
			}
		}
		f = 1;
		for (int j = 0; j < m; j++) {
			if (y[j] < x)f = 0;
		}
		if (f && o < ans)ans = o;
	}
	if (ans == 2000000)printf("-1\n");
	else printf("%d\n", ans);
}
