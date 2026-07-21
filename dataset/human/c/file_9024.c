#pragma warning(disable:4996)
#include<stdio.h>

int main(void) {
	int k, h, count = 0, n;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &h);
		if (h >= k) {
			++count;
		}
	}
	printf("%d", count);
	return 0;
}
