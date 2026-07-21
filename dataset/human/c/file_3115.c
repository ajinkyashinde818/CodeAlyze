#include<stdio.h>

int main(void) {
	int K, N;
	scanf("%d%d", &K, &N);
	int A[N], B[N], i;
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	B[0] = K - A[N - 1] + A[0];
	for (i = 1; i < N; i++) {
		B[i] = A[i] - A[i - 1];
	}
	int MAX = B[0];
	for (i = 1; i < N; i++) {
		if (MAX < B[i]) MAX = B[i];
	}
	printf("%d", K - MAX);

	return 0;
}
