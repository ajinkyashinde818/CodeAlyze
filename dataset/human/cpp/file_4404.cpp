#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

const int N = 100 * 1000 + 5;

int a[N], b[N];
set <pair <int, int> > s;
map <int, set <int> > mp;
int c[N], d[N];
map <int, vector <int> > adj;
map <int, bool> mark;

void dfs(int v) {
	mark[v] = true;
	for (auto u : adj[v]) {
		if (!mark[u]) {
			dfs(u);
		}
	}
}


int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[0] ^= a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		b[0] ^= b[i];
		if (a[i] != b[i]) {
			mp[b[i]].insert(i);
			s.insert({a[i], i});
		}
	}
	for (int i = 0; i <= n; i++) {
		c[i] = a[i];
		d[i] = b[i];
	}
	sort(c, c + n + 1);
	sort(d, d + n + 1);
	for (int i = 0; i <= n; i++) {
		if (c[i] != d[i]) {
			cout << -1;
			return 0;
		}
		if (a[i] != b[i]) {
			adj[i].push_back(a[i] + N);
			adj[i].push_back(b[i] + N);
			adj[a[i] + N].push_back(i);
			adj[b[i] + N].push_back(i);
			ans++;
		}
	}
	if (ans == 0) {
		cout << 0;
		return 0;
	}
	if (a[0] != b[0]) {
		ans -= 2;
	}
	else {
		if (adj[a[0] + N].size() != 0) {
			ans--;
		}
	}
	//cout << ans << endl;
	for (int i = 0; i <= n; i++) {
		if (a[i] != b[i] && !mark[i]) {
			dfs(i);
			ans++;
		}
	}
	cout << ans;
	return 0;
}
