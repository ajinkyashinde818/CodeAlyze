#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

int main(void) {
	int n,i;
	int an[200010];
	long long allsum[200010];
	unsigned long long minnum = 2ll << 49ll;
	long long x,y;
	scanf("%d",&n);
	for (i = 0; i < n; i++) {
		allsum[i] = 0;
	}
	for (i = 0; i < n; i++) {
		scanf("%d",&an[i]);
	}
	allsum[0] = an[0];
	for (i = 0; i < n - 1; i++) {
		allsum[i + 1] = allsum[i] + an[i + 1];
	}

	for (i = 0; i < n - 1; i++) {
		x = allsum[i];
		y = allsum[n - 1] - allsum[i];
		if (minnum > llabs(x - y)) {
			minnum = llabs(x - y);
		}
	}
	printf("%lld",minnum);
	return 0;
}
