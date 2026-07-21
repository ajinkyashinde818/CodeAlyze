#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, K, S;
	scanf("%d %d %d", &N, &K, &S);

	int i;
	for (i = 1; i <= K; i++) printf("%d ", S);
	for (; i <= N; i++) printf("%d ", S % 1000000000 + 1);
	fflush(stdout);
	return 0;
}
