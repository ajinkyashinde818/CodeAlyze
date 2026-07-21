/*input
4
0 1 2 3
1 0 3 2
*/
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define int long long
#define N 100005

int n;
int a[N], b[N];
multiset<int> st;
map<int, int> enc;
vector<vector<int> > e(N);
bool visited[N];

struct dsu {
	int par[N], sz[N];
	dsu() {
		for (int i = 1; i <= N - 4; i++) par[i] = i, sz[i] = 0;
	}
	int find(int x) {
		if (par[x] == x) return x;
		return par[x] = find(par[x]);
	}
	int size(int x) {
		return sz[find(x)];
	}
	void uni(int x, int y) {
		x = find(x); y = find(y); sz[y]++;
		if (x != y) {
			sz[y] += sz[x]; sz[x] = 0;
			par[x] = y;
		}
	}
} d;

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef UncleGrandpa
	freopen("1test.inp", "r", stdin);
#endif
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], a[n + 1] ^= a[i], st.insert(a[i]), enc[a[i]];
	st.insert(a[n + 1]); enc[a[n + 1]];
	for (int i = 1; i <= n; i++) {
		cin >> b[i], b[n + 1] ^= b[i];
		if (st.find(b[i]) != st.end()) st.erase(st.find(b[i]));
	}
	if (st.find(b[n + 1]) != st.end()) st.erase(st.find(b[n + 1]));
	if (st.size()) {
		cout << "-1" << endl;
		return 0;
	}
	int cur = 0;
	for (auto it = enc.begin(); it != enc.end(); it++) {
		it->se = ++cur;
	}
	for (int i = 1; i <= n + 1; i++) a[i] = enc[a[i]];
	for (int i = 1; i <= n + 1; i++) b[i] = enc[b[i]];
	for (int i = 1; i <= n + 1; i++) {
		if (a[i] != b[i]) {
			d.uni(a[i], b[i]);
		}
	}
	int ans = 0;
	if (d.size(a[n + 1])) {
		if (a[n + 1] == b[n + 1]) ans += d.size(a[n + 1]);
		else ans += d.size(a[n + 1]) - 1;
		visited[d.find(a[n + 1])] = true;
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[d.find(a[i])] && d.size(a[i]) > 0) {
			ans += d.size(a[i]) + 1;
			visited[d.find(a[i])] = true;
		}
	}
	cout << ans << endl;
}
