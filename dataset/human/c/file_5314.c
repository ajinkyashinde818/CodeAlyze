#include <stdio.h>
#include <stdlib.h>

#define INF 100010001
int main()
{
	int i,j;
	int N, M, X;
	int *C;
	int **A;
	long *sum;
	int nall;
	int s;
	long ans, cost;
	int ok;
	
	scanf("%d %d %d", &N, &M, &X);
	C = (int *)malloc(sizeof(int)*N);
	sum  = (long *)malloc(sizeof(long)*M);
	A = (int **)malloc(sizeof(int*)*N);
	for (i =0; i< N; i++) {
		A[i] = (int *)malloc(sizeof(int)*M);
	}
	for (i =0; i < N; i++) {
		scanf(" %d", &C[i]);
		for (j = 0; j < M; j++) {
			scanf(" %d", &A[i][j]);
		}
	}

	nall = 1 << N;
	ans = INF;
	/* 全探索 */
	for (s = 0; s < nall; s++) {
		cost = 0;
		ok = 1;
		for (j = 0; j < M; j++) {
			sum[j] = 0;
		}
		/* このセットでの合計金額costと スキルup sum[j] */
		for (i = 0; i < N; i++) {
			/* このセットがこの本iを含む時*/
			if (s>>i&1) {
				cost += C[i];
				for (j = 0; j < M; j++) {
					sum[j] += A[i][j];
				}
			}
		}
		for (j = 0; j < M; j++) {
			if (sum[j] < X) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			ans = (ans > cost)?cost:ans;
		}
	}
	if (ans == INF) {
		printf("-1\n");
	} else {
		printf("%ld\n", ans);
	}

	free(C);
	for (i = 0; i < N; i++) {
		free(A[i]);
	}
	free(A);

	return EXIT_SUCCESS;
}
