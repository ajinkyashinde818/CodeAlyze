#include <stdio.h>

int N, M;
char A[100][100];
char B[100][100];

int main(void) {
	int i, j, i2, j2;
	if (scanf("%d%d", &N, &M) != 2) return 1;
	for (i = 0; i < N; i++) {
		if (scanf("%s", A[i]) != 1) return 1;
	}
	for (i = 0; i < M; i++) {
		if (scanf("%s", B[i]) != 1) return 1;
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			int ok = 1;
			for (i2 = 0; i2 < M; i2++) {
				for (j2 = 0; j2 < M; j2++) {
					if (i + i2 >= N || j + j2 >= N || A[i + i2][j + j2] != B[i2][j2]) {
						ok = 0;
						i2 = M;
						break;
					}
				}
			}
			if (ok) {
				puts("Yes");
				return 0;
			}
		}
	}
	puts("No");
	return 0;
}
