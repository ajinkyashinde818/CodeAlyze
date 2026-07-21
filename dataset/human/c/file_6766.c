#include <stdio.h>

int N, K;
int A[271828];

int main(void) {
	int i;
	int ng = 0, ok = 1000000000;
	if (scanf("%d%d", &N, &K) != 2) return 1;
	for (i = 0; i < N; i++) {
		if (scanf("%d", &A[i]) != 1) return 1;
	}
	while (ng + 1 < ok) {
		int m = ng + (ok - ng) / 2;
		int count = 0;
		for (i = 0; i < N; i++) {
			count += (A[i] + m - 1) / m - 1;
		}
		if (count <= K) ok = m; else ng = m;
	}
	printf("%d\n", ok);
	return 0;
}
