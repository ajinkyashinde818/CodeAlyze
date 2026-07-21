/* Coached by Dukkha */
#include <stdio.h>

#define D 10
#define INF 1001

int main() {
	static int pp[D], cc[D];
	int d, g, i, b, ans;

	scanf("%d%d", &d, &g);
	for (i = 0; i < d; i++)
		scanf("%d%d", &pp[i], &cc[i]);
	ans = INF;
	for (b = 0; b < 1 << d; b++) {
		int p = 0, q = 0, a;

		for (i = 0; i < d; i++)
			if (b & 1 << i) {
				a = 100 * (i + 1);
				p += pp[i];
				q += pp[i] * a + cc[i];
			}
		if (q < g) {
			for (i = d - 1; i >= 0; i--)
				if ((b & 1 << i) == 0)
					break;
			a = 100 * (i + 1);
			if (i >= 0 && q + (pp[i] - 1) * a >= g) {
				int p_ = (g - q + a - 1) / a;

				p += p_;
				q += p_ * a;
			}
		}
		if (q >= g && ans > p)
			ans = p;
	}
	printf("%d\n", ans);
	return 0;
}
