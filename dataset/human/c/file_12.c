#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int r, g, b, n, r_n, g_n, sum,cnt = 0;
	scanf("%d%d%d%d", &r, &g, &b, &n);
	for (r_n=0; r_n <= n; r_n++) {
		g_n = 0;
		if (r_n * r + g_n * g > n)
			break;
		for (; g_n <= n - r_n; g_n++) {
			if (r_n * r + g_n * g > n)
				break;
			if ((n - r_n * r - g_n * g) % b == 0)
				cnt++;
		}
	}
	printf("%d\n", cnt);
}
