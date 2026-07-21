#include <stdio.h>

void merge_sort(int x[], int n)
{
	static int y[100001] = {};
	if (n == 1) return;
	merge_sort(&(x[0]), n/2);
	merge_sort(&(x[n/2]), (n+1)/2);
	
	int i, p, q;
	for (i = 0, p = 0, q = n/2; i < n; i++) {
		if (p >= n/2) y[i] = x[q++];
		else if (q >= n) y[i] = x[p++];
		else y[i] = (x[p] < x[q])? x[p++]: x[q++];
	}
	for (i = 0; i < n; i++) x[i] = y[i];
}

int main()
{
	int i, N, A[100001];
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &(A[i]));
	merge_sort(A, N);
	
	int l, r, tmp[100001];
	if (N == 2) {
		printf("%d\n%d %d\n", A[1] - A[0], A[1], A[0]);
	} else if (A[0] >= 0) {
		tmp[0] = A[0];
		tmp[1] = A[0] - A[N-1];
		for (i = 2; i < N - 1; i++) tmp[i] = tmp[i-1] - A[i-1];
		tmp[N-1] = A[N-2] - tmp[N-2];
		printf("%d\n%d %d\n", tmp[N-1], A[0], A[N-1]);
		for (i = 2; i < N - 1; i++) printf("%d %d\n", tmp[i-1], A[i-1]);
		printf("%d %d\n", A[N-2], tmp[N-2]);
	} else if (A[N-1] <= 0) {
		tmp[0] = A[N-1];
		tmp[1] = A[N-1] - A[0];
		for (i = 2; i < N - 1; i++) tmp[i] = tmp[i-1] - A[i-1];
		tmp[N-1] = tmp[N-2] - A[N-2];
		printf("%d\n%d %d\n", tmp[N-1], A[N-1], A[0]);
		for (i = 2; i < N - 1; i++) printf("%d %d\n", tmp[i-1], A[i-1]);
		printf("%d %d\n", tmp[N-2], A[N-2]);
	} else {
		tmp[0] = A[N-1];
		for (l = 1; A[l] <= 0; l++) tmp[l] = tmp[l-1] - A[l];
		tmp[l] = A[0];
		for (r = N - 2, i = l + 1; A[r] > 0; r--, i++) tmp[i] = tmp[i-1] - A[r];
		tmp[N] = tmp[l-1] - tmp[N-1];
		printf("%d\n", tmp[N]);
		for (i = 1; i < l; i++) printf("%d %d\n", tmp[i-1], A[i]);
		for (r = N - 2, i = l + 1; i < N; r--, i++) printf("%d %d\n", tmp[i-1], A[r]);
		printf("%d %d\n", tmp[l-1], tmp[N-1]);
	}
	fflush(stdout);
	return 0;
}
