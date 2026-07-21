#include <stdio.h>
int a[200000] = {};
int dis[200000] = {};
int main() {
	int k, n;
	scanf("%d%d", &k, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		if (i == n - 1) {
			dis[i] = k - a[i] + a[0];
		} else {
			dis[i] = a[i + 1] - a[i];
		}
	}
	int max = 0;
	for (int i = 0; i < n; i++) {
		//printf("dis[%d]:%d ", i,dis[i]);
		if (max < dis[i]) {
			max = dis[i];
		}
	}
	printf("%d\n", k - max);
	return 0;
}
