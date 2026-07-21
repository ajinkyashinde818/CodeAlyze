#include <stdio.h>

int main(void) {
	int K, S;
	int X;
	int answer = 0;
	if (scanf("%d%d", &K, &S) != 2) return 1;
	for (X = 0; X <= K && X <= S; X++) {
		int left = S - X;
		int Ymin = left - K;
		int Ymax = left;
		if (Ymin < 0) Ymin = 0;
		if (Ymax > K) Ymax = K;
		if (Ymin <= Ymax) answer += Ymax - Ymin + 1;
	}
	printf("%d\n", answer);
	return 0;
}
