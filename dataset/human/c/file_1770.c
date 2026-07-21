#include<stdio.h>
int main() {
	int i, N, t, A[30], B[30], C[30], ans = 0;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}
	for (i = 1; i <= N; i++) {
		scanf("%d", &B[i]);
	}
	for (i = 1; i <= N - 1; i++) {
		scanf("%d", &C[i]);
	}
	A[N + 1] = C[N] = 0;
	for (i = 1; i <= N; i++) {
		ans += B[A[i]];
		if (A[i] + 1 == A[i + 1])
			ans += C[A[i]];
	}
	printf("%d", ans);
	return 0;
}
