#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

unordered_map<int, int>T, W;
int a[N], b[N], n, h[N], t, f[N], ret;

int find (int x) { return x == f[x] ? x : f[x] = find(f[x]); }

int main () {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]), a[n] ^= a[i];
	for (int i = 0; i < n; ++i) scanf("%d", &b[i]), b[n] ^= b[i];
	for (int i = 0; i <= n; ++i) ++T[a[i]], --T[b[i]];
	for (auto u : T) if (u.second) return puts("-1"), 0;
	for (int i = 0; i <= n; ++i) if (i == n || a[i] != b[i]) h[t++] = a[i], h[t++] = b[i];
	sort(h, h + t);
	t = unique(h, h + t) - h;
	for (int i = 0; i <= n; ++i) if (i == n || a[i] != b[i]) {
		a[i] = lower_bound(h, h + t, a[i]) - h, b[i] = lower_bound(h, h + t, b[i]) - h;
		if (i < n) ++ret;
	}
	for (int i = 0; i < t; ++i) f[i] = i;
	for (int i = 0; i <= n; ++i) if (a[i] != b[i]) f[find(a[i])] = find(b[i]);
	for (int i = 0; i < t; ++i) if (find(i) == i) ++ret;
	printf("%d\n", ret - (bool)t);
	return 0;
}
