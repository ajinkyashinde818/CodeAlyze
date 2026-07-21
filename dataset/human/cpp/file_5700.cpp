#include <bits/stdc++.h>

const int MAXN = 100010;
int nxt[MAXN][2], end[MAXN], dep[MAXN], idx = 1;
char buf[MAXN];
typedef long long LL;
LL get(LL x) { return x ? 1 << __builtin_ctzll(x) : 0; }
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int n; LL L; std::cin >> n >> L;
	while (n --> 0) {
		std::cin >> buf; char * cur = buf;
		int now = 1;
		while (*cur) {
			int & nt = nxt[now][*cur++ - '0'];
			if (!nt) dep[nt = ++idx] = dep[now] + 1;
			now = nt;
		}
		end[now] = true;
	}
	LL ans = 0;
	for (int i = 1; i <= idx; ++i) if (!end[i])
		for (int j = 0; j != 2; ++j) if (!nxt[i][j])
			ans ^= get(L - dep[i]);
	std::cout << (ans ? "Alice" : "Bob") << std::endl;
	return 0;
}
