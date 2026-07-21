#include <stdio.h>

int main() {
	int a, b, k;
	scanf("%d %d %d", &a, &b, &k);
	for (int i = 100; i > 0; i--) {
		if ((a % i == 0) && (b % i == 0))
			k--;
		if (k < 1) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}
