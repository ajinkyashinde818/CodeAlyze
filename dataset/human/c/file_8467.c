#include <stdio.h>

void swap(int *, int *);

int main(void)
{
	int N, M, i, k;
	
	scanf("%d %d", &N, &M);
	int A[N];
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	for (k = 1; k <= M; k++) {
		for (i = 0; i < N-1; i++) {
			if (A[i] % k > A[i+1] % k) {
				swap(&A[i], &A[i+1]);
			}
		}
	}
	for (i = 0; i < N; i++) {
		printf("%d\n", A[i]);
	}
	
	return 0;
}

void swap(int *x, int *y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}
