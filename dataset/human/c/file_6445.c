#include <stdio.h>
#include <limits.h>
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) < (Y)) ? (Y) : (X))

int main()
{
	int N, i;
	int min_v = INT_MAX, max_v = INT_MIN;

	scanf("%d", &N);
	int R[N];
	for (i = 0; i < N; i++)
		scanf("%d", &R[i]);
	for (i = 0; i < N; i++) {
		max_v = MAX(max_v, R[i]-min_v);
		min_v = MIN(min_v, R[i]);
	}
	printf("%d\n", max_v);
	return 0;
}
