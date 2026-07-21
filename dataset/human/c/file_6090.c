#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main (void) {
	int i, j, n, max, buy, tmp;
	scanf("%d", &n);
	scanf("%d", &buy);
	max = INT_MIN;
	for (i = 1; i < n; i++) {
		scanf("%d", &tmp);
		if (max < tmp - buy) {
			max = tmp - buy;
		}
		if (buy > tmp) {
			buy = tmp;
		}
	}
	printf("%d\n", max);
	return 0;
}
