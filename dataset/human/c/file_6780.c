#include <stdio.h>

int main()
{
	int i, N, K, A[200001], max = 0;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) {
		scanf("%d\n", &(A[i]));
		if (A[i] > max) max = A[i];
	}

	int l = 1, r = max, m, tmp, count;
	while (l < r) {
		m = (l + r) / 2;
		for (i = 1, count = 0; i <= N; i++) {
			count += (A[i] - 1) / m;
			if (count > K) break;
		}
		if (count > K) l = m + 1;
		else r = m;
	}

	printf("%d\n", l);
	fflush(stdout);
	return 0;
}
