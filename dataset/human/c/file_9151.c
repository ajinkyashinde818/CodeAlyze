#include<stdio.h>

int main(void) {
	int i, j, n, k;
	scanf("%d%d", &n, &k);
	int h[n];
	for (i = 0; i<n; i++) {
		scanf("%d", &h[i]);
	}
	for (i = 0; i<n; i++) {
		if (h[i] >= k)
			j++;
	}
	printf("%d", j);

	return 0;
}
