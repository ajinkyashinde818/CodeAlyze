#include <stdio.h>
int main(void) {
	int n, k;
	int h[100000];
	int count = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i <= n; i++) {
		scanf("%d", &h[i]);
	}
	for (int i = 0; i <= n; i++) {
		if (h[i] >= k) {
			count++;
		}
	}
	printf("%d", count);
	return 0;
}
