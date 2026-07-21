#include<stdio.h>

int main()
{
	int N;
	int A[200000];
	int i, j;
	int tmp, max, min;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	max = A[1] - A[0];
	min = A[0];
	for (i = 1; i < N; i++) {
		tmp = A[i] - min;
		max = tmp > max ? tmp : max;
		min = min < A[i] ? min : A[i];
	}

	printf("%d\n", max);

	return 0;
}
