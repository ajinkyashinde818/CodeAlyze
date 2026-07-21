#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, N;
	long long A[100001];
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%lld", &(A[i]));
	
	long long min = llabs(A[1]), sum = 0, parity = 0;
	for (i = 1; i <= N; i++) {
		sum += llabs(A[i]);
		if (llabs(A[i]) < min) min = llabs(A[i]);
		if (A[i] < 0) parity ^= 1;
	}
	
	if (parity == 0) printf("%lld\n", sum);
	else printf("%lld\n", sum - min * 2);
	fflush(stdout);
	return 0;
}
