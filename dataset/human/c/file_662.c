#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, N, M;
	char A[52][52] = {}, B[52][52] = {};
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) scanf("%s", &(A[i][1]));
	for (i = 1; i <= M; i++) scanf("%s", &(B[i][1]));
	
	int j, k, l, flag = 0;
	for (i = 0; i <= N - M; i++) {
		for (j = 0; j <= N - M; j++) {
			for (k = 1; k <= M; k++) {
				for (l = 1; l <= M; l++) {
					if (A[i+k][j+l] != B[k][l]) break;
				}
				if (l <= M) break;
			}
			if (k > M) flag = 1;
		}
	}
	
	if (flag == 1) printf("Yes\n");
	else printf("No\n");
	fflush(stdout);
	return 0;
}
