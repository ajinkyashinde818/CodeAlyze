#include <stdio.h>

int main()
{
	int i, k, A, B, K;
	scanf("%d %d %d", &A, &B, &K);
	for (i = A, k = 0; i >= 1, k < K; i--) if (A % i == 0 && B % i == 0) k++;
	printf("%d\n", i + 1);
	fflush(stdout);
	return 0;
}
