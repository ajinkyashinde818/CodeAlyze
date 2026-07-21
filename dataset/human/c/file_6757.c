#include <stdio.h>

constexpr int kN = int(2E5 + 10), kInf = int(1E9 + 10);
int a[kN];

int Cut(int x, int n) {
	int ans = 0;
	for (int i = 1; i <= n; i++) ans += (a[i] - 1) / x;
	return ans;
}

int main() {
	int n, k, l, r, mid;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	l = 0, r = kInf;
	while (r - l > 1) {
		mid = (l + r) >> 1;
		if (Cut(mid, n) > k) l = mid;
		else r = mid;
	}	
	printf("%d\n", r);
}
