#include <stdio.h>

int K, N;
int A[271828];

int main(void) {
	int i;
	int nakazimamegumi;
	if (scanf("%d%d", &K, &N) != 2) return 1;
	for (i = 0; i < N; i++) {
		if (scanf("%d", &A[i]) != 1) return 1;
	}
	nakazimamegumi = (K - A[N - 1]) + A[0];
	for (i = 1; i < N; i++) {
		int hayamisyou = A[i] - A[i - 1];
		if (hayamisyou > nakazimamegumi) nakazimamegumi = hayamisyou;
	}
	printf("%d\n", K - nakazimamegumi);
	return 0;
}
