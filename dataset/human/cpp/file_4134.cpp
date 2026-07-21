#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<double, int> P;
const int N = (int)1e3 + 5;
//const ll INF = (ll)1e18;
const double INF = 1e18;

struct edge{
    int to;
    double cost;
//    edge(int _to, int _cost){
//        to = _to, cost = _cost;
//    }
};

int n;
vector<edge> G[N];
double dis[N];

void dijkstra(){

    fill(dis, dis+N, INF);
    dis[0] = 0;
    priority_queue<P, vector<P>, greater<P> > pque;
    pque.push({0, 0});

    while(!pque.empty()){
        P p = pque.top(); pque.pop();
        int i = p.second;
        double dist = p.first;
        if(dist > dis[i]) continue;

        for(edge e : G[i]){
            if(e.cost + dis[i] < dis[e.to]){
                dis[e.to] = e.cost + dis[i];
                pque.push({dis[e.to], e.to});
            }
        }
    }
}

double sx, sy, tx, ty;
double x[N], y[N], r[N];

int main() {
    cin >> x[0] >> y[0] >> x[1] >> y[1];
    cin >> n; n += 2;
    for(int i = 2; i < n; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            double dis = max(0.0, sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]))
                            - r[i] - r[j]);
            G[i].push_back({j, dis});
            G[j].push_back({i, dis});
        }
    }
    dijkstra();
    cout << fixed << setprecision(10) << dis[1] << endl;
}
