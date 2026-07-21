#include <stdio.h>
int main() {
	int N, i, count = 0, num = 0;
	int A[20];
	int B[20];
	int C[20];

	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);
	for (i = 0; i < N; i++)
		scanf("%d", &B[i]);
	for (i = 0; i < N - 1; i++)
		scanf("%d", &C[i]);

	for (i = 0; i < N; i++) {
		count += B[A[i] - 1];
		if (i != 0) {
			if (A[i] - 1 == num)
				count += C[num - 1];
		}
		num = A[i];
	}
	printf("%d", count);
	return 0;
}
