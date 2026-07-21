#include <stdio.h>

int main()
{
	int i, N, D, X, A[101];
	scanf("%d", &N);
	scanf("%d %d", &D, &X);
	for (i = 1; i <= N; i++) scanf("%d", &(A[i]));
	
	int ans = X;
	for (i = 1; i <= N; i++) ans += (D - 1) / A[i] + 1;

	printf("%d\n", ans);
	fflush(stdout);
	return 0;
}
