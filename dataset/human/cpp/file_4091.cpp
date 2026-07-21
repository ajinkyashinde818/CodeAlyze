#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string.h>
#include <cstdio>
#include <tuple>
#include <numeric>
using namespace std; using ll = long long; using ld = long double;  using pll = pair<ll, ll>;
using vl = vector<ll>; using vll = vector<vl>; using vpll = vector<pll>;
using vs = vector<string>; using tll = tuple<ll, ll, ll>; using vtll = vector<tll>;
const ld PI = 3.1415926535897932;
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define co(i) cout << i << endl;
#define co2(i,j) cout << i << " " << j << endl;
#define co3(i) cout << i << " ";
#define po(i) cout << i.first << " " << i.second << endl;
void in() {}
void debug_out() { cerr << endl; }
template<typename Head, typename... Tail>
void debug_out(Head h, Tail... t) {
	cerr << " " << h;
	if (sizeof...(t) > 0) cerr << " :";
	debug_out(t...);
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> vec) {
	for (size_t i = 0; i < vec.size(); i++)os << vec[i] << (i + 1 == vec.size() ? "" : " ");
	return os;
}
ll ctoi(char c) {
	switch (c) {
	case '0': return 0; case '1': return 1; case '2': return 2;
	case '3': return 3; case '4': return 4; case '5': return 5;
	case '6': return 6; case '7': return 7; case '8': return 8;
	case '9': return 9;  default: return 0;
	}
}
bool pairCompare(const pll firstElof, pll secondElof)
{
	return firstElof.first > secondElof.first;
}
//**Snippetリスト**//
//rep, vin, all, iteLoop, bitSearch, bitList, nod, digitDP, treeDP//
//gcdlcm, isPrime, eratos, primeFactorize, Npow, combination, divisor, modinv, doubling//
//dfs, bfs, dijkstra, WarshallFloyd, BellmanFord, UnionFind, Kruskal, RMQ, LCA//
ll i, j, k, l; ll N, M, K, H, W, L, X, Y, Z, R, Q;
ll MOD = 1000000007, INF = 1LL << 60, ans = 0, z = 0, o = 1;
vpll flag, D; vector<vector<pair<ll,ld>>> path;
//***********//
void dijkstra(ll s) {
	priority_queue<pll> PQ;
	vector<ld> D(N+2), color(N+2);
	for (ll i = 0; i < N+2; i++) {
		D[i] = INF;
		color[i] = 0;
	}
	D[s] = 0;
	PQ.push(make_pair(0, s));
	color[s] = 1;
	ll q = -1;
	while (!PQ.empty()) {
		pll f = PQ.top();
		PQ.pop();
		ll u = f.second;
		color[u] = 2;
		if (D[u] < f.first * q) {
			continue;
		}
		for (ll j = 0; j < path[u].size(); j++) {
			ll v = path[u][j].first;
			if (color[v] == 2) {
				continue;
			}
			if (D[v] > D[u] + path[u][j].second) {
				D[v] = D[u] + path[u][j].second;
				color[v] = 1;
				PQ.push(make_pair(D[v] * q, v));
			}
		}
	}
	cout << fixed << setprecision(10) << D[N + 1];
}
int main() {
	ll A, B, C, D;
	cin >> A >> B >> C >> D;
	cin >> N;
	vl X(N+2), Y(N+2), R(N+2);
	X[0] = A; Y[0] = B; R[0] = 0;
	X[N + 1] = C; Y[N + 1] = D; R[N + 1] = 0;
	for (i = 0; i < N; i++) {
		cin >> X[i+1] >> Y[i+1] >> R[i+1];
	}
	path.resize(N + 2);
	//始点0、終点N+1としてi→jへの路を
	for (i = 0; i < N+2; i++) {
		for (j = 0; j < N+2; j++) {
			if (i == j) continue;
			path[i].push_back(mp(j, (ld)max((ld)z,sqrt((ld)pow(X[i]-X[j],2)+(ld)pow(Y[i]-Y[j],2))-(R[i]+R[j]))));
		}
	}
	dijkstra(0);
}
