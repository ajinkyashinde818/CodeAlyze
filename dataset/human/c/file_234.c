#include <stdio.h>

long max(long a, long b) {
	return (a > b) ? a : b;
}


int main() {
	int i, N, j;
	long A[100000];
	long B[100000][2];

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%ld", &A[i]);
	}

	B[0][0] = A[0];
	B[0][1] = -A[0];

	for (i = 1; i < N - 1; i++) {
		B[i][0] = max(B[i - 1][0] + A[i], B[i - 1][1] - A[i]);
		B[i][1] = max(B[i - 1][0] - A[i], B[i - 1][1] + A[i]);
	}

	printf("%ld\n", max(B[N - 2][0] + A[N - 1], B[N - 2][1] - A[N - 1]));
	
	return 0;
}
