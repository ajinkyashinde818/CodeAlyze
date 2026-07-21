#include <stdbool.h>
#include <stdio.h>
typedef long long ll;
int main() {
	int n, a[200000], pt = 0, cnt = 0, dis[200000] = {0};
	bool isReached[200000] = {0};
	ll k;
	int f;
	scanf("%d%lld", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	isReached[0] = true;
	while (1) {
		// printf("%d", pt);
		pt = a[pt] - 1;
		// printf(">%d\n", pt);
		cnt++;
		if (isReached[pt]) {
			f = (k - dis[pt]) % (cnt - dis[pt]);
			// printf("%lld %d %d\n", k, dis[pt], cnt);
			break;
		}
		dis[pt] = cnt;
		isReached[pt] = true;
		if (cnt == k) {
			printf("%d\n", pt + 1);
			return 0;
		}
	}
	for (int i = 0; i < f; i++) {
		pt = a[pt] - 1;
	}
	printf("%d\n", pt + 1);
	return 0;
}
