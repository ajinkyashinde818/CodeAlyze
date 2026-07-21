#include <stdio.h>

int main() {
	int n, r, max, r_base;

	scanf("%d", &n);

	scanf("%d", &r_base);

	max = 1 - 1000000000;
	for (int i=0; i<n-1;i++) {
		scanf("%d", &r);
		if (max < r - r_base) {
			max = r - r_base;
		}
		if (r_base > r) {
			r_base = r;
		}
	}

	printf("%d\n", max);
}
