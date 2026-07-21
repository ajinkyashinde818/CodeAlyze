#include <stdio.h>

int N;
int A[32];
int B[32];
int C[32];

int main(void) {
	int i;
	int kugyu = 0;
	if (scanf("%d", &N) != 1) return 1;
	for (i = 1; i <= N; i++) {
		if (scanf("%d", &A[i]) != 1) return 1;
	}
	for (i = 1; i <= N; i++) {
		if (scanf("%d", &B[i]) != 1) return 1;
	}
	for (i = 1; i <= N - 1; i++) {
		if (scanf("%d", &C[i]) != 1) return 1;
	}
	kugyu += B[A[1]];
	for (i = 2; i <= N; i++) {
		kugyu += B[A[i]];
		if (A[i] == A[i - 1] + 1) kugyu += C[A[i - 1]];
	}
	printf("%d\n", kugyu);
	return 0;
}
