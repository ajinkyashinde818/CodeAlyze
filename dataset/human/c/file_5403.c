#include <stdio.h>

int main()
{
	int i, j, N, M, X, C[13], A[13][13];
	scanf("%d %d %d", &N, &M, &X);
	for (i = 1; i <= N; i++) {
		scanf("%d", &(C[i]));
		for (j = 1; j <= M; j++) scanf("%d", &(A[i][j]));
	}
	
	const int bit[13] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096};
	int min = 1 << 30, flag[13] = {}, tmp[13], cost;
	while (flag[N] == 0) {
		for (j = 1; j <= M; j++) tmp[j] = 0;
		for (i = 0, cost = 0; i < N; i++) {
			if (flag[i] == 1) {
				cost += C[i+1];
				for (j = 1; j <= M; j++) tmp[j] += A[i+1][j];
			}
		}
		for (j = 1; j <= M; j++) if (tmp[j] < X) break;
		if (j > M && cost < min) min = cost;
		
		for (i = 0; flag[i] == 1; i++);
		for (flag[i--] = 1; i >= 0; flag[i--] = 0);
	}
	if (min < 1 << 30) printf("%d\n", min);
	else printf("-1\n");
	fflush(stdout);
	return 0;
}
