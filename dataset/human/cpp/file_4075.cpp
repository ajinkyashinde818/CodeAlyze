#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <functional>
#include <array>
#include <queue>

using namespace std;

using P = pair<double, int>;
struct Edge {
    int to;
    double cost;
};

int V = 100;
constexpr int MAX_V = 1001000;
constexpr double INF = 1e17;
vector<Edge> G[MAX_V];
double d[MAX_V];

void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P>> que;
    fill(d, d + V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while(!que.empty()){
        P p = que.top();
        que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(const auto& e : G[v]){
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

double dis(double x1, double y1, double x2, double y2){
    const double dx = x1 - x2;
    const double dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

int main(){
    double xs, ys;
    cin >> xs >> ys;

    double xt, yt;
    cin >> xt >> yt;

    int N;
    cin >> N;
    V = N + 2;

    vector<double> x(N), y(N), r(N);
    for(int i = 0; i < N; ++i){
        cin >> x[i] >> y[i] >> r[i];
    }

    for(int i = 0; i < N; ++i){
        const double d1 = dis(xs, ys, x[i], y[i]) - r[i];
        G[0].push_back(Edge{i+1, max<double>(0, d1)});
        const double d2 = dis(xt, yt, x[i], y[i]) - r[i];
        G[N+1].push_back(Edge{i+1, max<double>(0, d2)});
    }

    const double dst = dis(xs, ys, xt, yt);
    G[0].push_back(Edge{N+1, max<double>(0, dst)});
    G[N+1].push_back(Edge{0, max<double>(0, dst)});

    for(int i = 0; i < N; ++i){
        const double d1 = dis(xs, ys, x[i], y[i]) - r[i];
        G[i+1].push_back(Edge{0, max<double>(0, d1)});
        const double d2 = dis(xt, yt, x[i], y[i]) - r[i];
        G[i+1].push_back(Edge{N+1, max<double>(0, d2)});
        for(int j = 0; j < N; ++j){
            if(i == j) continue;
            const double d0 = dis(x[i], y[i], x[j], y[j]) - r[i] - r[j];
            G[i+1].push_back(Edge{j+1, max<double>(0, d0)});
        }
    }

    dijkstra(0);
    printf("%.10lf\n", d[N+1]);
}
