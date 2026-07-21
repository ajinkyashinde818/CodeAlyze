#include <stdio.h>
typedef long long ll;
int min(int x, int y) {
	return x > y ? y : x;
}
int max(int x, int y) {
	return x < y ? y : x;
}
int a[200000];
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int amax = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		amax = max(amax, a[i]);
	}
	int ok = amax, ng = 0, mid;
	while (ok - ng > 1) {
		mid = (ng + ok) / 2;
		ll cutCnt = 0;
		for (int i = 0; i < n; i++) {
			cutCnt += (a[i] + mid - 1) / mid - 1;
		}
		if (cutCnt <= k)
			ok = mid;
		else
			ng = mid;
	}
	printf("%d\n", ok);
	return 0;
}
