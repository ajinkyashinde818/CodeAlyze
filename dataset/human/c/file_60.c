#include <stdio.h>
int main() {
	int r, g, b, n, cnt = 0;
	scanf("%d%d%d%d", &r, &g, &b, &n);
	for (int i = 0; i <= n / r; i++) {
		for (int j = 0; j <= n / g; j++) {
			int num = n - i * r - j * g;
			if (num >= 0 && num % b == 0) {
				cnt++;
				// printf("%d %d %d\n", i, j, num / b);
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}
