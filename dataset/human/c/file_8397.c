#include <stdio.h>

int main() {
	int N;
	scanf("%d",&N);
	char S[N];
	scanf("%s",S);
	int K;
	scanf("%d",&K);
	for (int i = 0; i < N; i++) {
		if (i == K - 1) continue;
		if (S[i] != S[K - 1]) {
			S[i] = '*';
		}
	}
	printf("%s\n",S);
	return 0;
}
