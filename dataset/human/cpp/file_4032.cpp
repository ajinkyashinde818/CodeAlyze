#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using vint = vector<int>;
using vll = vector<ll>;
using uint = unsigned int;
using ull = unsigned long long;

template<typename T> using uset = unordered_set<T>;
template<typename T1, typename T2> using umap = unordered_map<T1, T2>;

constexpr int INF = (1 << 30) - 1;
constexpr ll LLINF = 1LL << 60;
constexpr int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};
constexpr int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
constexpr char el = '\n';
constexpr int mod = 1000000007;

template<typename T> T gcd(T a, T b) { return (b ? gcd(b, a % b) : a); }
template<typename T> T lcm(T a, T b) { return (a / gcd(a, b) * b); }
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

template<typename T>
ostream& operator <<(ostream &os, vector<T> &v) {
	for (auto &u : v) os << u << el;
	return (os);
}

template<typename T>
istream& operator >>(istream &is, vector<T> &v) {
	for (auto &u : v) is >> u;
	return (is);
}


template<typename T>
struct Edge {
	int from, to;
	T cost;
	Edge () {}
	Edge (int from, int to, T cost ) : from(from), to(to), cost(cost) {}
	Edge (int to, T cost) : from(-1), to(to), cost(cost) {}
};

template<typename T>
vector<T> Dijkstra(int V, const vector<vector<Edge<T>>> &G, int s) {
	using Node = pair<T, int>;
	constexpr T INF = numeric_limits<T>::max();
	vector<T> d(V, INF);
	priority_queue<Node, vector<Node>, greater<Node>> pq;

	d[s] = 0;
	pq.emplace(0, s);
	while (!pq.empty()) {
		Node node = pq.top(); pq.pop();
		if (d[node.second] < node.first) continue;
		for (auto &e : G[node.second]) {
			T cost = e.cost + node.first;
			if (cost < d[e.to]) {
				d[e.to] = cost;
				pq.emplace(cost, e.to);
			}
		}
	}

	return (d);
}


double pdist(double x1, double y1, double x2, double y2) {
	return (sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)));
}

int main() {
	double sx, sy, tx, ty;	
	cin >> sx >> sy >> tx >> ty;
	int N; cin >> N;
	int V; V = N + 2;
	vector<double> X(V), Y(V), R(V);
	vector<vector<Edge<double>>>G(V);

	X[0] = sx, Y[0] = sy, R[0] = 0;
	X[N+1] = tx, Y[N+1] = ty, R[N+1] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> X[i] >> Y[i] >> R[i];
	}
	
	for (int i = 0; i < V; i++) {
		for (int j = i + 1; j < V; j++) {
			double dist = max(0.0, pdist(X[i], Y[i], X[j], Y[j]) - R[i] - R[j]);
			G[i].emplace_back(j, dist);
			G[j].emplace_back(i, dist);
		}
	}
	vector<double> ans = Dijkstra(V, G, 0);
	
	cout << fixed << setprecision(10) << ans[N+1] << endl;

	return (0);
}
