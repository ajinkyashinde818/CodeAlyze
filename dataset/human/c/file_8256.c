#include <stdio.h>

int main(void) {
	int N;
	char S[64];
	int K;
	int i;
	if (scanf("%d", &N) != 1) return 1;
	if (scanf("%63s", S) != 1) return 1;
	if (scanf("%d", &K) != 1) return 1;
	for (i = 0; i < N; i++) {
		putchar(S[i] == S[K - 1] ? (unsigned char)S[i] : '*');
	}
	putchar('\n');
	return 0;
}
