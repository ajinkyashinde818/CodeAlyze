#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
using namespace std;
int main(void) {
	char A[55][55];
	char B[55][55];
	int h,i,j,k,ok,N, M;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) {
		scanf(" %s", &A[i]);
	}
	for (i = 0; i < M; i++) {
		scanf(" %s", &B[i]);
	}

	for (h = 0; h <= N - M; h++) {
		for (i = 0; i <= N - M; i++) {
			ok = 1;
			for (j = 0; j < M; j++) {
				for (k = 0; k < M; k++) {
					if (A[h + j][i + k] != B[j][k]) {
						ok = 0; break;
					}
				}
				if (ok == 0) { break; }
			}
			if (ok == 1) { printf("Yes\n"); return 0; }
		}
	}
	printf("No\n");
	return 0;
}
