#include <stdio.h>

int main()
{
	int i, N, A[200001];
	long long K;
	scanf("%d %lld", &N, &K);
	for (i = 1; i <= N; i++) scanf("%d", &(A[i]));
	
	int j, flag[200001] = {};
	flag[1] = 1;
	for (i = 2, j = 1; flag[A[j]] == 0; i++, j = A[j]) flag[A[j]] = i;
	
	if ((long long)i - 1 > K) {
		for (j = 1; flag[j] <= K; j = A[j]);
		printf("%d\n", j);
		fflush(stdout);
		return 0;
	}
	
	int period = i - flag[A[j]];
	K = (K - flag[A[j]] + 1) % period;
	for (j = A[j], i = 0; i < K; i++, j = A[j]);
	printf("%d\n", j);
	fflush(stdout);
	return 0;
}
