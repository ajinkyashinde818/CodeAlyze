#include <stdio.h>

int main() {
	int k, s, x, y, z, cnt;

	scanf("%d%d", &k, &s);
	cnt = 0;
	for (x = 0; x <= k; x++)
		for (y = 0; y <= k && x + y <= s; y++) {
			z = s - x - y;
			if (z <= k)
				cnt++;
		}
	printf("%d\n", cnt);
	return 0;
}
