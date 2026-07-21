#include <bits/stdc++.h>

const int MAXN = 100010;
int B[MAXN], A[MAXN], n, idx, fa[MAXN], ans;
std::map<int, int> M;
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void merge(int x, int y) {
	x = find(x), y = find(y); ++ans;
	if (x != y) fa[x] = y, --ans;
}
int g(int x) { if (!M[x]) M[x] = ++idx, fa[idx] = idx, ++ans; return M[x]; }
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> A[i], A[n + 1] ^= A[i];
	for (int i = 1; i <= n; ++i) std::cin >> B[i], B[n + 1] ^= B[i];
	for (int i = 1; i <= n + 1; ++i) ++M[A[i]], --M[B[i]];
	for (auto t : M) if (t.second) return std::cout << -1 << std::endl, 0;
	for (int i = 1; i <= n + 1; ++i) if (A[i] != B[i]) merge(g(A[i]), g(B[i]));
	std::cout << ans - (!!M[A[n + 1]]) - (A[n + 1] != B[n + 1]) << std::endl;
	return 0;
}
