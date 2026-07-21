#include <stdio.h>
#include <string.h>

#pragma warning(disable:4996)


int main(void) {
	int r, g, b, n;
	scanf("%d %d %d %d", &r, &g, &b, &n);
	int sum = 0;
	int tmp0;
	int tmp1;
	for (int i = 0; i * r <= n; ++i) {
		for (int j = 0; j * g <= n; ++j) {
			if (n - r * i - g * j < 0) continue;
			if ((n - r * i - j * g) % b == 0) {
				++sum;
			}
		}
	}
	printf("%d\n", sum);
	return 0;
}
