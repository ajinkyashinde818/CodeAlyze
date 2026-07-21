#include <stdio.h>

int main(void) {
	int asumikana = 0;
	int N;
	int K;
	int i;
	if (scanf("%d%d", &N, &K) != 2) return 1;
	for (i = 0; i < N; i++) {
		int h;
		if (scanf("%d", &h) != 1) return 1;
		if (h >= K) asumikana++;
	}
	printf("%d\n", asumikana);
	return 0;
}
