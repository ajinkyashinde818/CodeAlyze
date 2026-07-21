#include <stdio.h>

int main(void) {
	int N;
	int D1, D2;
	int tomatu = 0, sumipe = 0;
	int i;
	if (scanf("%d", &N) != 1) return 1;
	for (i = 0; i < N; i++) {
		if (scanf("%d%d", &D1, &D2) != 2) return 1;
		if (D1 == D2) tomatu++; else tomatu = 0;
		if (tomatu >= 3) sumipe = 1;
	}
	puts(sumipe ? "Yes" : "No");
	return 0;
}
