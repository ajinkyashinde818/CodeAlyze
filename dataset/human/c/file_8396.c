#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define pai 3.1415926535

int main(void) {
	int N;
	scanf("%d", &N);
	char S[11];
	scanf("%s", S);
	int K;
	scanf("%d", &K);

	for (int i = 0; i < N; i++) {
		if (S[i] != S[K - 1]) {
			S[i] = '*';
		}
	}
	printf("%s\n", S);

	return 0;
}
