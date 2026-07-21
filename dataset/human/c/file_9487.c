#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	int N, D, X;
	scanf("%d", &N);
	scanf("%d%d", &D, &X);
	int A[N];
	int i, j, k;
	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);

	int num = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < D; j += A[i])
			num += 1;
//		printf("i: %d, num: %d\n", i, num);
	}

	printf("%d\n", num + X);

	return 0;
}
