#include <bits/stdc++.h>

template <typename T> inline void rd(T& x) {
	int si = 1; char c = getchar(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
	while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int kN = 4e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, len, cnt = 0, tot, a[kN], b[kN], d[kN], buc[kN], fa[kN];
bool vis[kN];
int Find(int x) { return fa[x] == x ? x : fa[x] = Find(fa[x]); }
void Visit(int x) { if(!vis[x]) ++tot; vis[x] = true; }
void Merge(int x, int y) {
	int f_x = Find(x), f_y = Find(y);
	if(f_x == f_y) return;
	Visit(f_x); Visit(f_y);
	fa[Find(x)] = Find(y); --tot;
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n);
		for(int i = 1; i <= n + 1; ++i) fa[i] = i;
		for(int i = 1; i <= n; ++i) rd(a[i]), d[i] = a[i], a[n + 1] ^= a[i];
		for(int i = 1; i <= n; ++i) rd(b[i]);
		d[n + 1] = a[n + 1]; std::sort(d + 1, d + n + 2);
		len = std::unique(d + 1, d + n + 2) - d - 1;
		for(int i = 1; i <= n + 1; ++i) {
			a[i] = std::lower_bound(d + 1, d + len + 1, a[i]) - d;
			++buc[a[i]];
			if(i <= n) {
				int buf = std::lower_bound(d + 1, d + len + 1, b[i]) - d;
				if(d[buf] != b[i]) return printf("-1\n"), 0;
				b[i] = buf; --buc[buf];
			}
		}
		for(int i = 1; i <= len; ++i) {
			if(buc[i] < 0) return printf("-1\n"), 0;
			if(buc[i] == 1) b[n + 1] = i;
		}
		for(int i = 1; i <= n; ++i)
			if(a[i] != b[i]) Merge(a[i], b[i]), ++cnt;
		printf("%d\n", cnt + tot - vis[a[n + 1]]);
	} return 0;
}
