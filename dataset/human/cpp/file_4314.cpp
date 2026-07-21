#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5+5;

int n, a[MAXN], b[MAXN];
int s = 0;
map<int, int> ma;

bool y = 0;
vector<int> g[MAXN];
map<int, int> m;
int a1[MAXN];
int comp = 0;
bool vis[MAXN];

void dfs(int v) {
	vis[v] = 1;
	for (int i = 0; i < g[v].size(); ++i)
		if (!vis[g[v][i]])
			dfs(g[v][i]);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a1[i] = a[i];
		s ^= a[i];
		ma[a[i]]++;
	}

	sort(a1, a1+n);
	for (int i = 0; i < n; ++i)
		m[a1[i]] = i;
	//all sequences we can achieve are permutations of a except maybe
	// with one element replaced with the sum

	if (m.count(s) == 0)
		m[s] = n;
	
	for (int i = 0; i < n; ++i)
		cin >> b[i];

	for (int i = 0; i < n; ++i) {
		if (a[i] == b[i])
			continue;
		g[m[a[i]]].push_back(m[b[i]]);
		g[m[b[i]]].push_back(m[a[i]]);
	}

	for (int i = 0; i <= n; ++i) {
		if (!vis[i] && g[i].size() > 0) {
			++comp;
			dfs(i);
		}
	}

	for (int i = 0; i < n; ++i) {
		if (b[i] == s && y == 0) {
			y = 1;
			continue;
		}

		if (ma[b[i]] == 0) {
			cout << "-1\n";
			return 0;
		}

		ma[b[i]]--;
	}

	if (y == 0) {
		int ct = 0;
		for (int i = 0; i < n; ++i)
			ct += (a[i] != b[i]);
		if (ct == 0)
			cout << "0\n";
		else
			cout << ct+comp << "\n";
		return 0;
	} else {
		int ct = 0;
		for (int i = 0; i < n; ++i)
			ct += (a[i] != b[i]);
		if (ct == 0)
			cout << "0\n";
		else
			cout << ct+comp-1 << "\n";
	}
}
