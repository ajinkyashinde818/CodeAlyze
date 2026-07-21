#include <stdio.h>
	
int main()
{
	int i, N, A[21], B[21], C[21], ans = 0;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &(A[i]));
	for (i = 1; i <= N; i++) {
		scanf("%d", &(B[i]));
		ans += B[i];
	}
	for (i = 1; i < N; i++) scanf("%d", &(C[i]));
	for (i = 1; i < N; i++) if (A[i] == A[i+1] - 1) ans += C[A[i]];
	printf("%d", ans);
	fflush(stdout);
	return 0;
}
