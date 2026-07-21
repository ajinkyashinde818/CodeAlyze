#include <stdio.h>

int main() {
	int N;
	scanf("%d",&N);
	int A[N], B[N], C[N-1];
	for (int i = 0; i < N; i++) {
		scanf("%d",&A[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d",&B[i]);
	}
	for (int i = 0; i < N-1; i++) {
		scanf("%d",&C[i]);
	}

	int sum = 0, tmp1, tmp2;
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			tmp1 = A[i];
			sum += B[tmp1-1];
		}
		else {
			tmp2 = A[i];
			sum += B[tmp2-1];
			if (tmp2 == tmp1 + 1) {
				sum += C[tmp1-1];
			}
			tmp1 = tmp2;
		}
	}
	printf("%d\n", sum);
	return 0;
}
