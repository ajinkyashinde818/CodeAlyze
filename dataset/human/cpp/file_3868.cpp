#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

const double INF = 1e18;

template <typename T>
struct Edge
{
    int to;
    T cost;
};

template <typename T>
struct WeightedGraph
{
    int n;
    vector<vector<Edge<T>>> g;
    
    WeightedGraph(int n) : n(n){
        g.resize(n);
    }
    
    void init(int n_){
        n = n_;
        g.resize(n_);
    }
    
    void add_edge(int from, int to, T cost){
        g[from].push_back((Edge<T>){to, cost});
    }
};

template <typename T>
vector<T> Dijkstra(WeightedGraph<T> &g, int s){
    int n = g.n;
    vector<T> d(n);
    vector<bool> used(n);
    fill(d.begin(), d.end(), INF);
    fill(used.begin(), used.end(), false);
    d[s] = 0;
    while(true){
        int now = -1;
        for(int i = 0; i < n; i++){
            if(!used[i] && (now == -1 || d[i] < d[now])) now = i;
        }
        if(now == -1) break;
        used[now] = true;
        for(Edge<T> e : g.g[now]) d[e.to] = min(d[e.to], d[now] + e.cost);
    }
    return d;
}

int main()
{
    double x[1005], y[1005], r[1005];
    cin >> x[0] >> y[0] >> x[1] >> y[1];
    r[0] = r[1] = 0;
    int n;
    cin >> n;
    n += 2;
    for(int i = 2; i < n; i++){
        cin >> x[i] >> y[i] >> r[i];
    }
    WeightedGraph<double> g(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            g.add_edge(i, j,
                       max(0.0, sqrt((x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i])) - r[i] - r[j]));
        }
    }
    vector<double> d = Dijkstra(g, 0);
    cout << fixed << setprecision(15) << d[1] << endl;
}
