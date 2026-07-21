// Aizu Vol-3 0319: Programming Contest
// 2017.8.25

#include <stdio.h>
#include <stdlib.h>

int p[103];

int cmp(int *a, int *b) { return *b - *a; }

int main()
{
	int N, i;

	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", p + i);
	qsort(p, N, sizeof(p[0]), cmp);
	for (i = 0; i < N; i++) if (p[i] <= i)  break;
	printf("%d\n", i);
	return 0;
}
