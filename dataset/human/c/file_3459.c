#include <stdio.h>
#include <inttypes.h>

int N;
int A[271828];
uint64_t K;

int dest[281828][70];

int main(void) {
	int i, j;
	int mofu = 1;
	if (scanf("%d%" SCNu64, &N, &K) != 2) return 1;
	for (i = 1; i <= N; i++) {
		if (scanf("%d", &A[i]) != 1) return 1;
	}
	for (i = 1; i <= N; i++) {
		dest[i][0] = A[i];
	}
	for (j = 1; j < 70; j++) {
		for (i = 1; i <= N; i++) {
			dest[i][j] = dest[dest[i][j - 1]][j - 1];
		}
	}
	for (i = 0; i < 64; i++) {
		if ((K >> i) & 1) mofu = dest[mofu][i];
	}
	printf("%d\n", mofu);
	return 0;
}
