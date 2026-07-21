#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <functional>
#include <stack>
#include <utility>
#include <map>
#include <queue>
#include <set>
#include <array>
#include <climits>

using namespace std;

typedef long long ll;
//typedef pair<ll, ll> P;
typedef  double LD;


const ll MOD = 10e9 + 7;
const LD INF = 999999999999999;
const ll MAX_V = 10e3;
const LD EPS = 10e-12;
const LD PI = 3.14159265359;

struct edge { int to; double cost; };
typedef pair<double, int> P; //firstは最短距離,secondは頂点の番号

int V;
vector<edge> G[MAX_V];
LD dmin[MAX_V];

void dijkstra(int s) {
	priority_queue<P, vector<P>, greater<P> > que; //小さいものから取り出す
	fill(dmin, dmin + V+2, INF);
	dmin[s] = 0;
	que.push(P(0, s));


	while (!que.empty()) {
		P p = que.top(); que.pop();
		ll v = p.second;
		if (dmin[v] + EPS < p.first)continue;
		for (int i = 0; i<G[v].size(); i++) {
			edge e = G[v][i];
			if (dmin[e.to] > dmin[v] + e.cost + EPS) {
				dmin[e.to] = dmin[v] + e.cost;
				que.push(P(dmin[e.to], e.to));
			}
		}
	}
}

int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };

ll sx, sy, gx, gy,x[1010],y[1010],r[1010];

int main() {
	cin >> sx >> sy >> gx >> gy >> V;
	x[0] = sx; y[0] = sy; r[0] = 0;
	x[V + 1] = gx; y[V + 1] = gy; r[V + 1] = 0;
	for (int i = 1; i <= V; i++) {
		cin >> x[i] >> y[i] >> r[i];
	}
	for (int i = 0; i <= V + 1; i++) {
		for (int j = i + 1; j <= V + 1; j++) {
			LD dist = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);
			LD co;
			if (dist <= (r[i] + r[j])*(r[i] + r[j])) {
				co = 0;
			}
			else {
				co = sqrt(dist) - LD(r[i] + r[j]);
			}
			G[i].push_back({ j,co });
			G[j].push_back({ i,co });

		}
	}
	V += 2;
	dijkstra(0);
	printf("%.12lf", dmin[V-1]);
	return 0;
}
