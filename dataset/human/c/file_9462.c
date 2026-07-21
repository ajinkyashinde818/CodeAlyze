#include <stdio.h>

int main() {
	int n, d, x, a;
	int chocolate = 0;
	scanf("%d %d %d", &n, &d, &x);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a);
		for(int j = 1; j <= d; j += a, chocolate++)
			;
	}
	printf("%d\n", chocolate + x);
	return 0;
}
