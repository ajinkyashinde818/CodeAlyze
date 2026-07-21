#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int n;
int a[100001];
int b[100001];
int currXorA = 0;
int currXorB = 0;
map<int, int> mpA, mpB;
map<int, vector<int> > g, gr;
set<int> used;
vector<int> order;
vector<int> component;

void dfs1 (int v) {
	used.insert(v);
	for (int i=0; i<g[v].size(); ++i)
		if (!used.count(g[v][i]))
			dfs1(g[v][i]);
	order.push_back (v);
}
 
void dfs2 (int v) {
	used.insert(v);
	component.push_back (v);
	for (size_t i=0; i<gr[v].size(); ++i)
		if (!used.count(gr[v][i]))
			dfs2(gr[v][i]);
}

int get(vector<int>& com) {
	if (com.size() == 1) return 0;
	
	for (int x : com) {
		if (x == currXorA || x == currXorB) {
			return 0;
		} 
	}
	return 1;
}
 
int main() {
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		currXorA ^= a[i];
	}
	a[n++] = currXorA;
	
	for (int i = 0; i < n - 1; i++) {
		cin >> b[i];
		currXorB ^= b[i];
	}
	b[n - 1] = currXorB;
	
	for (int i = 0; i < n; i++) {
		if (mpA.find(a[i]) == mpA.end()) mpA[a[i]] = 0;
		mpA[a[i]]++;
	}
	
	for (int i = 0; i < n; i++) {
		if (mpB.find(b[i]) == mpB.end()) mpB[b[i]] = 0;
		mpB[b[i]]++;
	}
	
	for (pair<int, int> curr : mpB) {
		int x = curr.first;
		int cnt = curr.second;
		if (mpA.find(x) == mpA.end()) {
			cout << -1;
			return 0;
		}
		if (cnt != mpA[x]) {
			cout << -1;
			return 0;
		}
	}
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			if (i != n - 1) ans++;
			gr[a[i]].push_back(b[i]);
			g[b[i]].push_back(a[i]);
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i] && !used.count(a[i])) {
			dfs1(a[i]);
		}
	}
	used.clear();
	for (int i=0; i<order.size(); ++i) {
		int v = order[order.size() - 1 - i];
		if (!used.count(v)) {
			dfs2(v);
			ans += get(component);
			component.clear();
		}
	}
	
	cout << ans;
	
	return 0;
}
