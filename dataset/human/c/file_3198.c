#include <stdio.h>

int main() {
	int K, N, A[1000000] = { 0 }, max = 0;
	scanf("%d%d", &K, &N);
	for (int i = 0; i < N; i++)scanf("%d", &A[i]);
	for (int i = 0; i < N-1 ; i++) if (A[i + 1] - A[i] > max) {
		max = A[i + 1] - A[i];
	}
	if (K - A[N - 1] + A[0] > max)max = K - A[N-1] + A[0];
	printf("%d", K - max);
	return 0;
}
