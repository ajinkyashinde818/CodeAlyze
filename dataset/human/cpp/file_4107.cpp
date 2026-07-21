#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include<iomanip>
using namespace std;
using ll=long long;

const ll INF=1000000000000000000;
const ll MAX_V=1005;

struct edge {
    ll to;
    double cost;
};

// <最短距離, 頂点の番号>
using P = pair<double, ll>;

ll V;
vector<edge> G[MAX_V];
double d[MAX_V];

void dijkstra(ll s) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        ll v = p.second;
        if (d[v] < p.first) continue;

        for (ll i=0; i<G[v].size(); ++i) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

ll points[MAX_V][3];
int main() {
    cin >> points[0][0] >> points[0][1] >> points[1][0] >> points[1][1];
    cin >> V;
    V+=2;
    for (ll i=2; i<V; ++i) {
        cin >> points[i][0] >> points[i][1] >> points[i][2];
    }
    for (ll i=0; i<V; ++i) {
        for (ll j=i+1; j<V; ++j) {
            double cost=sqrt((points[i][0]-points[j][0])*(points[i][0]-points[j][0])+
                (points[i][1]-points[j][1])*(points[i][1]-points[j][1]));
            cost=max(0.0,cost-points[i][2]-points[j][2]);
            edge e1 = {j, cost};
            G[i].push_back(e1);
            edge e2 = {i, cost};
            G[j].push_back(e2);
        }
    }
    dijkstra(0);
    cout << setprecision(16) << d[1] << endl;
}
