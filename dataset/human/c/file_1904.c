#include <stdio.h>

int main() {
	int N, A[21] = {0}, B[21] = {0}, C[21] = {0};
	int b;
	int i;
	int ans = 0;
	scanf("%d", &N);

	for(i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}
	for(i = 1; i <= N; i++) {
		scanf("%d", &B[i]);
	}
	for(i = 1; i <= N-1; i++) {
		scanf("%d", &C[i]);
	}


	for(i = 1; i <= N; i++) {
		ans += B[A[i]];
		if(i > 1 && A[i-1] + 1 == A[i]) {
			ans += C[A[i-1]];
		}
	}

	printf("%d\n", ans);
	return 0;
}
