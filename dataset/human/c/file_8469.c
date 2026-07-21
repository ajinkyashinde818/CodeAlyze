#include <stdio.h>

int main(void) {
	int N, M;
	int A[101];
	int i;
	int k;
	if (scanf("%d%d", &N, &M) != 2) return 1;
	for (i = 1; i <= N; i++) {
		if (scanf("%d", &A[i]) != 1) return 1;
	}
	for (k = 1; k <= M; k++) {
		int baton = 1;
		while (baton != N) {
			if (A[baton] % k > A[baton + 1] % k) {
				int temp = A[baton];
				A[baton] = A[baton + 1];
				A[baton + 1] = temp;
			}
			baton = baton + 1;
		}
	}
	for (i = 1; i <= N; i++) {
		printf("%d\n", A[i]);
	}
	return 0;
}
