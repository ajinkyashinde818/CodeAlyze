#include<stdio.h>

int main(void) {
	int N, K;
	char S[10], s[10];

	scanf("%d", &N);
	scanf("%s", S);
	scanf("%d", &K);

	for (int i = 0; i < N; i++) {
		if (S[i] != S[K - 1]) {
			s[i] = '*';
		}
		else {
			s[i] = S[i];
		}
	}
	s[N] = '\0';
	printf("%s\n", s);

	return 0;
}
