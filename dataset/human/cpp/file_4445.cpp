#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
template<typename T> inline void chkmin(T &a, const T &b) { a = a < b ? a : b; }
template<typename T> inline void chkmax(T &a, const T &b) { a = a > b ? a : b; }

const int MAXN = 100005;
int a[MAXN], b[MAXN], par[MAXN], lab[MAXN], n;
unordered_map<int, int> mp, id;

int find(int x) { return x == par[x] ? x : par[x] = find(par[x]); }

int main() {
	scanf("%d", &n);
	int tot = 0, x = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		++mp[a[i]];
		if (!id[a[i]]) id[a[i]] = ++tot;
		x ^= a[i];
	}
	++mp[x];
	if (!id[x]) id[x] = ++tot;
	a[n + 1] = x, x = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", b + i);
		if (--mp[b[i]] < 0) return puts("-1"), 0;
		x ^= b[i];
	}
	if (--mp[x] < 0) return puts("-1"), 0;
	b[n + 1] = x;
	for (int i = 1; i <= tot; i++) par[i] = i;
	lab[find(id[a[n + 1]])] = 1;
	int res = 0;
	for (int i = 1; i <= n + 1; i++) {
		if (a[i] == b[i]) continue;
		int p = id[a[i]], q = id[b[i]];
		par[find(p)] = find(q);
		if (i <= n) ++res;
		lab[find(q)] = 1;
	}
	for (int i = 1; i <= tot; i++) res += lab[i] && par[i] == i;
	printf("%d\n", res - 1);
	return 0;
}
