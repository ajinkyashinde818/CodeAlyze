#include <stdio.h>

int main() {
	int a, b, k, n;

	scanf("%d%d%d", &a, &b, &k);
	for (n = a < b ? a : b; n > 0; n--)
		if (a % n == 0 && b % n == 0)
			if (--k == 0) {
				printf("%d\n", n);
				return 0;
			}
	return 0;
}
