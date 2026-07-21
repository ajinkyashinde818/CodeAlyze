#include <stdio.h>

int main()
{
	int i, K, N, A[200001];
	scanf("%d %d", &K, &N);
	for (i = 1; i <= N; i++) scanf("%d", &(A[i]));

	int max = A[1] + (K - A[N]);
	for (i = 1; i < N; i++) {
		if (A[i+1] - A[i] > max) max = A[i+1] - A[i];
	}
	printf("%d\n", K - max);
	fflush(stdout);
	return 0;
}
