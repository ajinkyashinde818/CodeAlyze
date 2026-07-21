#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>


int main(void) {
	int N = 0, M = 0;
	char A[52][52] = { "\0" };
	char B[52][52] = {"\0"};
	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%s", A[i]);
	}
	for (int i = 0; i < M; i++) {
		scanf("%s", B[i]);
	}
	for (int i = 0; i <= N - M; i++) {
		for (int j = 0; j <= N - M; j++) {
			bool tf = false;
			for (int k = 0; k < M; k++) {
				for (int l = 0; l < M; l++) {
					if (A[i + k][j + l] != B[k][l])
						goto NEXT;
				}
			}
			tf = true;
		NEXT:;
			if (tf == true) {
				printf("Yes\n");
				return 0;
			}
		}
	}
	printf("No\n");
	return 0;
}
