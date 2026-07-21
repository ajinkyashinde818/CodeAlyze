#include <math.h>
#include <stdio.h>
typedef long long ll;
int main() {
	int n, a[100000], mCnt = 0, min = 1e9;
	ll ans = 0, sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += abs(a[i]);
		if (a[i] < 0)
			mCnt++;
		if (min > abs(a[i]))
			min = abs(a[i]);
	}
	if (mCnt % 2 == 0) {
		ans = sum;
	} else {
		ans = sum - 2 * min;
	}
	printf("%lld\n", ans);
	return 0;
}
