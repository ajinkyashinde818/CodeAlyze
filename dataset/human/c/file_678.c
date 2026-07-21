#include <stdio.h>

int main(void) {
	int N, M;
	char A[55][55], B[55][55];
	int i, j;

	scanf("%d %d", &N, &M);
	for(i = 0; i < N; i++) {
		scanf("%s", A[i]);
	}
	for(i = 0; i < M; i++) {
		scanf("%s", B[i]);
	}

	for(i = 0; i < N - M + 1; i++) {
		for(j = 0; j < N - M + 1; j++) {
			int k, l;
			int flag = 0;
			for(k = 0; k < M; k++) {
				for(l = 0; l < M; l++) {
					if(A[i+k][j+l] != B[k][l]) {
						flag = 1;
						break;
					}
				}
				if(flag) break;
			}
			if(!flag) {
				printf("Yes\n");
				return 0;
			}
		}
	}
	printf("No\n");

	return 0;
}
