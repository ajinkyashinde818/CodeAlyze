#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "bitset"

using namespace std;

//const long long int MOD = 998244353;
const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

class UnionFind {
	vector<int>parent;
	vector<int>rank;
public:
	UnionFind(int num) {
		num++;
		parent.resize(num);
		rank.resize(num);
		for (int i = 0; i < num; i++) {
			parent[i] = i;
			rank[i] = 0;
		}
	}
	int Find(int node) {
		if (parent[node] == node)return node;
		else return parent[node] = Find(parent[node]);
	}
	void Unite(int u, int v) {
		u = Find(u);
		v = Find(v);
		if (u == v)return;
		if (rank[u] < rank[v])parent[u] = v;
		else {
			parent[v] = u;
			if (rank[u] == rank[v])rank[u]++;
		}
	}
	bool Check_Same(int u, int v) {
		return Find(u) == Find(v);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N);
	vector<int>w(N);
	int box = 0;
	for (auto &i : v) {
		cin >> i;
		box ^= i;
	}
	v.push_back(box);
	box = 0;
	for (auto &i : w) {
		cin >> i;
		box ^= i;
	}
	w.push_back(box);
	if (v == w) {
		cout << 0 << endl;
		return 0;
	}
	auto vv = v;
	auto ww = w;
	sort(vv.begin(), vv.end());
	sort(ww.begin(), ww.end());
	if (vv != ww) {
		cout << -1 << endl;
		return 0;
	}
	vv.erase(unique(vv.begin(), vv.end()), vv.end());
	map<int, int>ms;
	for (int i = 0; i < vv.size(); i++)ms[vv[i]] = i;
	UnionFind uf(vv.size());
	vector<int>flag(vv.size());
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (v[i] != w[i]) {
			ans++;
			uf.Unite(ms[v[i]], ms[w[i]]);
			flag[ms[v[i]]] = 1;
			flag[ms[w[i]]] = 1;
		}
	}
	set<int>s;
	for (int i = 0; i < vv.size(); i++) {
		if(flag[i])s.insert(uf.Find(i));
	}
	ans += s.size();
	for (int i = 0; i < N; i++) {
		if (v.back() == w[i]&&w[i]!=v[i]) {
			ans--;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
