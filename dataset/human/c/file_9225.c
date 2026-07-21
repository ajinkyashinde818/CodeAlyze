#include <stdio.h>

int main() {
	int i, a[1000000], k,n , cnt = 0;

	scanf("%d %d", &n, &k);

	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (i = 0; i <n; i++) {
		if (a[i] >= k) {
			cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}
