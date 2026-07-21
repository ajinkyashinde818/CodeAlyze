#include <stdio.h>

int M, N;
int A[114514];

int main(void) {
	int i;
	if (scanf("%d%d", &M, &N) != 2) return 1;
	for (i = 0; i < N; i++) {
		if (scanf("%d", &A[i]) != 1) return 1;
	}
	if (M <= 2) {
		int hoge = 0, fuga = 0;
		for (i = 0; i < N; i++) {
			if (A[i] != (i % 2 == 0 ? 1 : 2)) hoge++;
			if (A[i] != (i % 2 == 0 ? 2 : 1)) fuga++;
		}
		printf("%d\n", hoge <= fuga ? hoge : fuga);
	} else {
		int miyukiti = 0;
		for (i = 1; i < N; i++) {
			if (A[i - 1] == A[i]) {
				miyukiti++;
				i++;
			}
		}
		printf("%d\n", miyukiti);
	}
	return 0;
}
