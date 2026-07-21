#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int llintcmp(const void *a, const void *b) {
	long long c = *(long long*)a-*(long long*)b;
	if (c>0LL) return -1;
	else if (c==0LL) return 0;
	else return 1;
}

long long a[300010];

int main(void) {
	int i, N;
	long long T=0LL;

	scanf("%d", &N);
	for (i=0;i<3*N;i++) scanf("%lld", &a[i]);

	qsort(a,3*N,sizeof(long long),llintcmp);
	for (i=0;i<2*N;i+=2) T += a[i+1];
	printf("%lld\n", T);	

	return 0;
}
