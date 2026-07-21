#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<cassert>
#include<queue>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct edge {
    int v;
    double w;
    edge() {}
    edge(int v, double w) : v(v), w(w) {};
};

vector<double> dijkstra(int n, vector<vector<edge> >& G, int s) {
    vector<double> d(n, 1e18); d[s] = 0;
    priority_queue<pair<ll, int> > que;
    que.push(make_pair(0ll, s));
    while (!que.empty()) {
        auto p = que.top(); que.pop();
        int u = p.second;
        ll dist = -p.first;
        if (dist > d[u]) continue;
        for (edge e : G[u]) {
            if (d[e.v] > d[u]+e.w) {
                d[e.v] = d[u] + e.w;
                que.push(make_pair(-d[e.v], e.v));
            }
        }
    }
    return d;
}

const int MAXN = 1010;
int X[MAXN], Y[MAXN], R[MAXN];

int main() {
	int xs, ys, xt, yt;
	cin >> xs >> ys >> xt >> yt;
	int N;
	cin >> N;
	X[0] = xs;
	Y[0] = ys;
	X[N+1] = xt;
	Y[N+1] = yt;
	for (int i = 1; i <= N; i++) {
		cin >> X[i] >> Y[i] >> R[i];
	}
	N += 2;
	vector<vector<edge> > G(N);
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			double dx = X[i]-X[j];
			double dy = Y[i]-Y[j];
			double d = sqrt(dx*dx+dy*dy);
			if (d < R[i] + R[j]) {
				G[i].emplace_back(j, 0);
				G[j].emplace_back(i, 0);
			} else {
				G[i].emplace_back(j, d-R[i]-R[j]);
				G[j].emplace_back(i, d-R[i]-R[j]);
			}
		}
	}
	auto d = dijkstra(N, G, 0);
	printf("%.10lf\n", d[N-1]);
	return 0;
}
