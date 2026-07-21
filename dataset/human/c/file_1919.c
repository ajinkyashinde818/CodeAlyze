#include <stdio.h>

int main(void) {
	int N;
	scanf("%d", &N);
	int A[N];
	int B[N];
	int C[N];
	int i;
	for(i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	for(i = 0; i < N; i++) {
		scanf("%d", &B[i]);
	}
	for(i = 0; i < N; i++) {
		scanf("%d", &C[i]);
	}
	int sum = 0;
	for (i = 0; i < N; i++) {
		sum += B[A[i] - 1];
		if (i - 1 >= 0 && A[i] - A[i - 1] == 1) {
			sum += C[A[i - 1] - 1];
		}
	}
	printf("%d", sum);
	return 0;

}
