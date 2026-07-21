#include <stdio.h>
#include <string.h>

int main() {
	int N, M, i, j, k, l, flag;
	scanf("%d %d", &N, &M);
	char A[N][N], B[M][M];
	for (i = 0; i < N; i++) {
		scanf("%s", A[i]);
	}
	for (i = 0; i < M; i++) {
		scanf("%s", B[i]);
	}
	for (i = 0; i <= N - M; i++) {
		for (j = 0; j <= N - M; j++) {
			flag = 0;
			for (k = 0; k < M; k++) {
				for (l = 0; l < M; l++) {
					if (A[i + k][j + l] != B[k][l]) {
						flag = 1;
						break;
					}
				}
			}
			if (flag == 0) {
				printf("Yes\n");
				return 0;
			}
		}
	}
	
	printf("No\n");
	return 0;
}
