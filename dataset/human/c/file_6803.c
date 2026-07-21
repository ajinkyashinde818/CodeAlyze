#include<stdio.h>
#include<stdlib.h>
#define TYPE int
cmp_r(const void *a, const void *b) { return *(TYPE *)b - *(TYPE *)a; }

int main() {
	int N;
	long long tmp = 0, ans = 0;
	scanf("%d", &N);
	int *A = (int *)malloc(sizeof(int) * 3 * N);
	for (int i = 0; i < 3 * N; i++)
	{
		scanf("%d", &A[i]);
	}
	qsort(A, 3 * N, sizeof(TYPE), cmp_r);
	//for (int i = 0; i < 3 * N; i++)
	//{
	//	printf("%d", A[i]);
	//}
	for (int i = 1; i < 2 * N; i += 2)
	{
		tmp += (long long)A[i];
	}
	ans = tmp;
	printf("%lld\n", ans);
	return 0;
}
