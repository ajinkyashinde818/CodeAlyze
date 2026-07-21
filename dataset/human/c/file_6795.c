#include <stdio.h>
#include <stdlib.h>

int y[300001];
 
void merge_sort(int x[], int n)
{
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
	int i, N, a[300001];
	scanf("%d", &N);
	for (i = 0; i < N * 3; i++) scanf("%d", &(a[i]));
	
	merge_sort(a, N * 3);
	
	long long sum = 0;
	for (i = 1; i <= N; i++) sum += a[N * 3 - i * 2];
	
	printf("%lld\n", sum);
	fflush(stdout);
	return 0;
}
