#include <stdio.h>

int main() {
	int N;
	int Ni[100000];
	int i;
	int K;
	int count = 0;

	scanf("%d %d", &N, &K);

	for (i = 0; i < N; i++) {
		scanf("%d", &Ni[i]);

	}

	for (i = 0; i < N; i++) {
		if (Ni[i] >= K) {
			count++;
		}
	}
	printf("%d\n", count);
	return 0;
}
