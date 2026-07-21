#include <stdio.h>

int
main() {
	int k, s;
	int ret = scanf("%d %d", &k, &s);
	if (k < 2 || k > 2500) return 0;
	if (s < 0 || s > (3 * k)) return 0;
	ret = 0;
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j <= k; j++) {
			int t = s - i - j;
			if (t >= 0 && t <= k) {
				ret++;
			}
		}
	}
	printf("%d\n", ret);
	return 0;
}
