#include <stdio.h>

int main(void) {
	int K, S, i, j, k, count = 0;

	scanf("%d%d", &K, &S);

	for (i = 0; i <= K; i++) {
		for (j = i; j <= K; j++) {
			for (k = j; k <= K; k++) {
				if (i + j + k == S) {
					if (i == j && j == k) {
						count++;
					}
					else if (i == j || j == k || k == i) {
						count += 3;
					}
					else {
						count += 6;
					}
				}
			}
		}
	}

	printf("%d\n", count);

	return 0;
}

int fact(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	return n * fact(n - 1);
}
