#include <stdio.h>
int main() {
	int i;

	int N;
	int A[20], B[20], C[20];
	int ans = 0;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		A[i] -= 1;
	}
	
	for (i = 0; i < N; i++) {
		scanf("%d", &B[i]);
	}

	for (i = 0; i < N - 1; i++) {
		scanf("%d", &C[i]);
	}

	for (i = 0; i < N; i++) {
		ans += B[A[i]];
		if (i != 0 && A[i] - A[i - 1] == 1) {
			ans += C[A[i - 1]];
		}
	}

	printf("%d", ans);

	return 0;
}
