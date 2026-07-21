#include <stdio.h>

int main(void) {
	int A, B, K;
	int count, i;
	if (scanf("%d%d%d", &A, &B, &K) != 3) return 1;
	count = 0;
	for (i = A; i > 0; i--) {
		if (A % i == 0 && B % i == 0) {
			count++;
			if (count >= K) {
				printf("%d\n", i);
				return 0;
			}
		}
	}
	puts("ERROR!!!!!");
	return 0;
}
