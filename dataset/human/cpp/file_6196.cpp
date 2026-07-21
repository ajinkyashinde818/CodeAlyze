#include <bits/stdc++.h>

using namespace std;

int n;
long long c, x[100005], v[100005], y[100005], z[100005], ans, la, lb;

int main() {
	scanf("%d%lld", &n, &c);
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld", x + i, v + i);
		// x[i] += x[i - 1];
		v[i] += v[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		y[i] = max(y[i - 1], (v[n] - v[n - i]) - (c - x[n - i + 1]));
		z[i] = max(z[i - 1], (v[n] - v[n - i]) - (c - x[n - i + 1]) * 2);
	}
	for (int i = 0; i <= n; i++) {
		la = max(la, v[i] - x[i] * 2);
		lb = max(lb, v[i] - x[i]);
		ans = max(ans, la + y[n - i]);
		ans = max(ans, lb + z[n - i]);
	}
	printf("%lld\n", ans);
	return 0;
}
