#include <stdio.h>

int main(void) {
	int N, K, S;
	int i;
	if (scanf("%d%d%d", &N, &K, &S) != 3) return 1;
	for (i = 0; i < N; i++) {
		if (i > 0) putchar(' ');
		printf("%d", i < K ? S : (S == 1000000000 ? 1 : (S + 1)));
	}
	putchar('\n');
	return 0;
}
