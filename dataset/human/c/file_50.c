#include <stdio.h>

int main() {
	int r, g, b, n;

	scanf("%d%d%d%d", &r, &g, &b, &n);

	int count = 0;
	for (int i = 0; i <= n; i++) {
		if (i * r > n) break;
		for (int j = 0; j <= n; j++){
			if (i * r + j * g > n) break;
			if (((n - i * r - j * g) / b) == (float)(n - i * r - j * g) / b) {
				count += 1;
			}
		}
	}

	printf("%d\n", count);

	return 0;
}
