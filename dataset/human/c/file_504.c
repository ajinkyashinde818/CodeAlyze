#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, a[200000];
	long long sum = 0, Spt = 0, min = 1e18;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	for (int i = 0; i < n - 1; i++) {
		Spt += a[i];
		if (min > llabs(Spt - (sum - Spt))) {
			min = llabs(Spt - (sum - Spt));
		}
	}
	printf("%lld\n", min);
	return 0;
}
