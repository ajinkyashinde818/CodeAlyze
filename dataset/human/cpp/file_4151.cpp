#include <bits/stdc++.h>
using namespace std;

double INF = 1e18;

vector<double> dijkstra(int s, int n, vector<double> cost[]){
    vector<double> dist(n, INF);
    vector<bool> used(n, false);
    dist[s] = 0;
    while(true){
        int v = -1;
        for(int u=0; u<n; u++){
            if(!used[u] && (v == -1 || dist[u] < dist[v])) v = u;
        }
        if(v == -1) break;
        used[v] = true;
        for(int u=0; u<n; u++){
            dist[u] = min(dist[u], dist[v] + cost[v][u]);
        }
    }
    return dist;
}

int main(){
    int X[1002], Y[1002], R[1002] = {0};
    for(int i=0; i<2; i++) cin >> X[i] >> Y[i];
    int N;
    cin >> N;
    for(int i=2; i<N+2; i++) cin >> X[i] >> Y[i] >> R[i];
    N += 2;
    vector<double> cost[1002];
    for(int i=0; i<N; i++) for(int j=0; j<N; j++){
        double x = X[i] - X[j];
        double y = Y[i] - Y[j];
        cost[i].push_back(max(0.0, sqrt(x*x + y*y) - R[i] - R[j]));
    }
    auto dist = dijkstra(0, N, cost);
    cout << fixed << setprecision(10) << dist[1] << endl;
}
