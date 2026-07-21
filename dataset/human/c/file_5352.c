#include <stdio.h>

#define INF 1111111111

int N, M, X;
int C[16];
int A[16][16];

int main(void) {
	int i, j;
	int search, smax;
	int answer = INF;
	if (scanf("%d%d%d", &N, &M, &X) != 3) return 1;
	for (i = 0; i < N; i++) {
		if (scanf("%d", &C[i]) != 1) return 1;
		for (j = 0; j < M; j++) {
			if (scanf("%d", &A[i][j]) != 1) return 1;
		}
	}
	smax = 1 << N;
	for (search = 0; search < smax; search++) {
		int cost = 0;
		int rikaido[16] = {0};
		int ok = 1;
		for (i = 0; i < N; i++) {
			if ((search >> i) & 1) {
				cost += C[i];
				for (j = 0; j < M; j++) rikaido[j] += A[i][j];
			}
		}
		for (i = 0; i < M; i++) ok = ok && rikaido[i] >= X;
		if (ok && cost < answer) answer = cost;
	}
	printf("%d\n", answer < INF ? answer : -1);
	return 0;
}
