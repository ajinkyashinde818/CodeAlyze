#include <stdio.h>

int N, M;
int a[271828], b[271828];

char hitotume[271828];

int main(void) {
	int i;
	int asumisu = 0; /* イエス！アスミス！ */
	if (scanf("%d%d", &N, &M) != 2) return 1;
	for (i = 0; i < M; i++) {
		if (scanf("%d%d", &a[i], &b[i]) != 2) return 1;
	}
	for (i = 0; i < M; i++) {
		if (a[i] == 1) hitotume[b[i]] = 1;
		if (b[i] == 1) hitotume[a[i]] = 1;
	}
	for (i = 0; i < M; i++) {
		if (hitotume[a[i]] && b[i] == N) asumisu = 1;
		if (hitotume[b[i]] && a[i] == N) asumisu = 1;
	}
	puts(asumisu ? "POSSIBLE" : "IMPOSSIBLE");
	return 0;
}
