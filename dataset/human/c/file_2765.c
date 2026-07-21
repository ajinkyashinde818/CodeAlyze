#include <stdio.h>

int main() {
	int K, S, X, Y, Z, count = 0, i, j, k;
	scanf("%d %d", &K, &S);
	for (i = 0; i <= K; i++) {
		if (i == S) {
			count++;
			break;
		}
		for (j = 0; j <= K; j++) {
			if (i + j == S) {
				count++;
				break;
			} else if (S - (i + j) <= K) {
				count++;
			}
		}
	}
	printf("%d\n", count);
	return 0;
}
