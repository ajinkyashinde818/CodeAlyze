#include <bits/stdc++.h>

const int N = 200005;

std::map<int, int> id;

int n, a[N], b[N], c[N], d[N], f[N], ans, tot = 0;
int active(int x) {
	if (id.count(x)) return id[x];
	else return id[x] = ++tot, f[tot] = tot;
}
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
void link(int x, int y) { f[find(x)] = find(y); }

int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> a[i], a[0] ^= a[i];
	for (int i = 1; i <= n; ++i) std::cin >> b[i], b[0] ^= b[i];
	for (int i = 0; i <= n; ++i) c[i] = a[i], d[i] = b[i];
	std::sort(c, c + n + 1), std::sort(d, d + n + 1);
	for (int i = 0; i <= n; ++i) if (c[i] != d[i]) return std::cout << "-1\n", 0;
	for (int i = 0; i <= n; ++i) if (a[i] != b[i]) link(active(a[i]), active(b[i])), ++ans;
	for (int i = 1; i <= tot; ++i) ans += i == find(i);
	if (a[0] != b[0]) ans -= 2;
	else
		for (int i = 1; i <= n; ++i)
			if (a[i] != b[i] && a[i] == a[0]) {--ans; break;}
	std::cout << ans << '\n';
	return 0;
}
