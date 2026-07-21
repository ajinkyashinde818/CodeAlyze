#include <iostream>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cstring>
#include<string>
#include<cassert>
#include<cmath>
#include<climits>
#include<iomanip>
#include<bitset>
#include<unordered_map>

using namespace std;

#define MOD 1000000007
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define rep(i,j,n) for(ll (i)=(j);(i)<(n);(i)++)
#define FOR(i,c) for(decltype((c).begin())i=(c).begin();i!=(c).end();++i)
#define ll long long
#define ull unsigned long long
#define all(hoge) (hoge).begin(),(hoge).end()
typedef pair<ll, ll> P;
const long long INF = 1LL << 60;
typedef vector<ll> Array;
typedef vector<Array> Matrix;


template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

//グラフ関連
struct Edge {//グラフ
	ll to, cap, rev;
	Edge(ll _to, ll _cap, ll _rev) {
		to = _to; cap = _cap; rev = _rev;
	}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void add_edge(Graph& G, ll from, ll to, ll cap, bool revFlag, ll revCap) {
	G[from].push_back(Edge(to, cap, (ll)G[to].size()));
	if (revFlag)G[to].push_back(Edge(from, revCap, (ll)G[from].size() - 1));
}

class SumSegTree {
private:

	int _sum(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l)return 0;    // 交差しない
		if (a <= l && r <= b)return dat[k];   // a,l,r,bの順で完全に含まれる
		else {
			int s1 = _sum(a, b, 2 * k + 1, l, (l + r) / 2); // 左の子
			int s2 = _sum(a, b, 2 * k + 2, (l + r) / 2, r); // 右の子
			return s1 + s2;
		}
	}
public:
	int n, height;
	vector<int> dat;

	// 初期化（_nは最大要素数）
	SumSegTree(int _n) {
		n = 1;
		height = 1;
		while (n < _n) {
			n *= 2;
			height++;
		}
		dat = vector<int>(2 * n - 1, 0);
	}

	// 場所i(0-indexed)にxを足す
	void add(int i, int x) {
		i += n - 1; // i番目の葉ノードへ
		dat[i] += x;
		while (i > 0) { // 下から上がっていく
			i = (i - 1) / 2;
			dat[i] += x;
		}
	}

	// 区間[a,b)の総和。ノードk=[l,r)に着目している。
	int sum(int a, int b) {
		return _sum(a, b, 0, 0, n);
	}
};

void Dijkstra(Graph& G, ll s, Array& d) {//O(|E|log|V|)
	d.resize(G.size());
	REP(i, d.size())d[i] = INF;
	d[s] = 0;
	priority_queue<P, vector<P>, greater<P>> q;
	q.push(make_pair(0, s));
	while (!q.empty()) {
		P a = q.top();
		q.pop();
		if (d[a.second] < a.first)continue;
		REP(i, G[a.second].size()) {
			Edge e = G[a.second][i];
			if (d[e.to] > d[a.second] + e.cap) {
				d[e.to] = d[a.second] + e.cap;
				q.push(make_pair(d[e.to], e.to));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n;
	cin >> n;
	Array a(n, 0);
	REP(i, n) cin >> a[i];

	Array sum(n + 1, 0);
	REP(i, n) sum[i + 1] = sum[i] + a[i];

	ll ans = INF;
	for (int i = 0; i < n-1;i++) {
		ll sum1 = sum[i + 1] - sum[0];
		ll sum2 = sum[n] - sum[i + 1];
		if (abs(sum1 - sum2) < ans) ans = abs(sum1 - sum2);
	}

	cout << ans << endl;

	return 0;
}
