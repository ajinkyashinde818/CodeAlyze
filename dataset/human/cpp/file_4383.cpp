#include <bits/stdc++.h>

typedef std::pair <int, int> pr;
const int N = 100054;

int n, V;
int a[N], b[N];
int ck[N], p[N], size[N];
pr D[N];

int ancestor(int x) {return p[x] == x ? x : (p[x] = ancestor(p[x]));}

inline bool Union(int x, int y) {
	if ((x = ancestor(x)) == (y = ancestor(y))) return true;
	return size[x] < size[y] ? (p[x] = y, size[y] += size[x]) : (p[y] = x, size[x] += size[y]);
}

int main() {
	int i, j, ans = 0; V = 0;
	scanf("%d", &n), ++n;
	for (i = 1; i < n; ++i) scanf("%d", a + i), *a ^= a[i];
	for (i = 1; i < n; ++i) scanf("%d", b + i), *b ^= b[i];
	for (i = 0; i < n; ++i) D[i] = pr(a[i], i);
	std::sort(D, D + n);
	for (i = 0; i < n; ++i) a[D[i].second] = (i && D[i].first == D[i - 1].first ? V - 1 : (D[V] = D[i], V++));
	for (i = 0; i < n; ++i) {
		j = std::lower_bound(D, D + V, pr(b[i], 0)) - D;
		if (j == V || D[j].first != b[i]) return puts("-1"), 0;
		b[i] = j;
	}
	for (i = 0; i < n; ++i) ++ck[a[i]], --ck[b[i]];
	if (std::count(ck, ck + V, 0) != V) return puts("-1"), 0;
	std::iota(p, p + V, 0), std::fill(size, size + V, 1);
	for (i = 0; i < n; ++i) if (a[i] != b[i]) Union(a[i], b[i]), ++ans;
	for (i = 0; i < V; ++i) ans += p[i] == i && size[i] != 1;
	ans -= (*a == *b ? size[ancestor(*a)] != 1 : 2);
	printf("%d\n", ans);
	return 0;
}
