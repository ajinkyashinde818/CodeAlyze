#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll MOD = (1e+9)+7;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef pair<P, int> PP;
struct edge { int to; ld cost; };
ld d[1002];
vector<edge> G[1002];
void dijkstra(int s) {
	priority_queue<P, vector<P>, greater<P>>que;
	fill(d, d + 1002, (ld)INF);
	d[s] = 0;
	que.push(P(0, s));
	while (!que.empty()) {
		P p = que.top(); que.pop();
		int v = p.second;
		if (d[v] < p.first)continue;
		for (int i = 0; i < (int)G[v].size(); i++) {
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}
struct cir { ld x, y, r; };
ld dis(cir x, cir y) {
	ld d = sqrt(pow(y.x - x.x, 2) + pow(y.y - x.y, 2));
	ld res = d - x.r - y.r;
	if (res < 0)return 0;
	else return res;
}
int main() {
	cout << fixed << setprecision(10);
	ld xs, ys, xt, yt;
	cin >> xs >> ys >> xt >> yt;
	int n; cin >> n;
	cir a[1002];
	rep(i, n) {
		ld x, y, r; cin >> x >> y >> r;
		a[i] = { x,y,r };
	}
	a[n] = { xs,ys,0 };
	a[n + 1] = { xt,yt,0 };
	rep(i, n + 2) {
		Rep(j, i + 1, n + 2) {
			ld d = dis(a[i], a[j]);
			G[i].push_back({ j,d });
			G[j].push_back({ i,d });
		}
	}
	dijkstra(n);
	cout << d[n + 1] << endl;
	return 0;
}
