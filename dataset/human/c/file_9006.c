#include <stdio.h>

int main(void) {
	int n, c;

	while (1) {
		scanf("%d", &n);
		if (n == 0) break;

		c = 0;
		while (1) {
			if (n == 1) break;
			else if (n % 2 == 0) {
				n /= 2;
				c++;
			}
			else {
				n *= 3;
				n += 1;
				c++;
			}
		}
		printf("%d\n", c);
	}
	return 0;
}
