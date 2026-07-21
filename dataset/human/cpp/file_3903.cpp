#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;
typedef long long ll;
typedef pair<double, ll> P;
struct edge { ll to; double cost; };
vector<edge> G[100010];
ll n;
const ll INF = 100000000000000000;
double sx, sy, tx, ty, x[1010], y[1010], r[1010], d[1010];

void dijkstra(ll s){
    priority_queue<P, vector<P>, greater<P>> que;
    fill(d, d + n + 2, INF);
    d[s] = 0;
    que.push(P(0, s));
    while(!que.empty()){
        P p = que.top(); que.pop();
        ll v = p.second;
        if (d[v] < p.first) continue;
        for (ll i = 0; i < G[v].size(); i++){
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main(void){
    // Your code here!
    cin >> sx >> sy >> tx >> ty >> n;
    for (ll i = 1; i <= n; i++){
        cin >> x[i] >> y[i] >> r[i];
    }
    for (ll i = 1; i <= n; i++){
        for (ll j = i + 1; j <= n; j++){
            double len = max(sqrt(pow((x[i] - x[j]), 2) + pow((y[i] - y[j]), 2)) - r[i] - r[j], (double)0);
            G[i].push_back(edge{j, len});
            G[j].push_back(edge{i, len});
        }
    }
    for (ll i = 1; i <= n; i++){
        double len = max(sqrt(pow((x[i] - sx), 2) + pow((y[i] - sy), 2)) - r[i], (double)0);
        G[0].push_back(edge{i, len});
        len = max(sqrt(pow((x[i] - tx), 2) + pow((y[i] - ty), 2)) - r[i], (double)0);
        G[i].push_back(edge{n + 1, len});
    }
    dijkstra(0);
    double ans = min(d[n + 1], sqrt(pow(sx - tx, 2) + pow(sy - ty, 2)));
    printf("%.10lf\n", ans);
}
