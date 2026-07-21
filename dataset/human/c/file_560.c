#include <stdio.h>

#define N 200000
#define INF 0x3f3f3f3f3f3f3f3fLL

long long llabs(long long n) {
	return n < 0 ? -n : n;
}

int main() {
	static int aa[N];
	int n, i;
	long long snukesum, raccoonsum, min;

	scanf("%d", &n);
	raccoonsum = 0;
	for (i = 0; i < n; i++) {
		scanf("%d", &aa[i]);
		raccoonsum += aa[i];
	}
	snukesum = 0;
	min = INF;
	for (i = 0; i < n - 1; i++) {
		long long diff;

		snukesum += aa[i];
		raccoonsum -= aa[i];
		diff = llabs(snukesum - raccoonsum);
		if (min > diff)
			min = diff;
	}
	printf("%lld\n", min);
	return 0;
}
