#include <iostream>
#include <cstring>
#include <cstdio>
int n, v1[100005], v2[100005];
long long m, ans, x1[100005], x2[100005], max[100005];
void Add(int x, long long v) {
	for (; x <= n; x += x & -x)
		max[x] = std::max(max[x], v);
}
long long Max(int x) {
	long long Max = 0;
	for (; x; x -= x & -x)
		Max = std::max(Max, max[x]);
	return Max;
}
void Calc(long long x[], int v[]) {
	memset(max, 0, sizeof(max));
	long long sum = 0, dis = 0;
	for (int i = 1; i <= n; ++i) {
		sum += v[i];
		dis = x[i];
		Add(i, sum - 2 * dis);
	}
	sum = 0;
	dis = 0;
	for (int j = n; j; --j) {
		sum += v[j];
		dis = m - x[j];
		ans = std::max(ans, sum - dis + Max(j - 1));
	}
}
int main() {
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%lld %d", &x1[i], &v1[i]);
	Calc(x1, v1);
	for (int i = 1; i <= n; ++i)
		x2[i] = m - x1[n - i + 1], v2[i] = v1[n - i + 1];
	Calc(x2, v2);
	printf("%lld\n", ans);
}
