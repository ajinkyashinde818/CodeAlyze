#include <stdio.h>
#include <stdlib.h>

#define N 100000
#define M 100000
#define INF 0x3f3f3f3f3f3f3f3fLL

int main() {
	static long long ss[N], tt[M];
	int n, m, q, i, j;

	scanf("%d%d%d", &n, &m, &q);
	for (i = 0; i < n; i++)
		scanf("%lld", &ss[i]);
	for (j = 0; j < m; j++)
		scanf("%lld", &tt[j]);
	while (q--) {
		long long x, xs1, xs2, xt1, xt2, d, ans;
		int lower, upper;

		scanf("%lld", &x);
		lower = -1, upper = n;
		while (upper - lower > 1) {
			i = (lower + upper) / 2;
			if (ss[i] < x)
				lower = i;
			else
				upper = i;
		}
		xs1 = lower == -1 ? -1 : ss[lower];
		xs2 = upper == n ? -1 : ss[upper];
		lower = -1, upper = m;
		while (upper - lower > 1) {
			j = (lower + upper) / 2;
			if (tt[j] < x)
				lower = j;
			else
				upper = j;
		}
		xt1 = lower == -1 ? -1 : tt[lower];
		xt2 = upper == m ? -1 : tt[upper];
		ans = INF;
		if (xs1 != -1 && xt1 != -1) {
			d = x - (xs1 < xt1 ? xs1 : xt1);
			if (ans > d)
				ans = d;
		}
		if (xs1 != -1 && xt2 != -1) {
			d = x - xs1 + xt2 - xs1;
			if (ans > d)
				ans = d;
			d = xt2 - x + xt2 - xs1;
			if (ans > d)
				ans = d;
		}
		if (xs2 != -1 && xt1 != -1) {
			d = xs2 - x + xs2 - xt1;
			if (ans > d)
				ans = d;
			d = x - xt1 + xs2 - xt1;
			if (ans > d)
				ans = d;
		}
		if (xs2 != -1 && xt2 != -1) {
			d = (xs2 > xt2 ? xs2 : xt2) - x;
			if (ans > d)
				ans = d;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
