#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
double INF = 1e20;
int MOD = 1e9+7;
int N;
double graph[1002][1002];  //0:start 1:goal
double dijkstra(int s) {
    vector<double> dist(N, INF);
    vector<int> used(N);
    dist[s] = 0;
    while (1) {
        int v = -1;
        for (int j = 0; j < N; j++)
            if (!used[j] && (v == -1 || dist[j] < dist[v])) v = j;
        if (v == -1) break;
        used[v] = true;
        for (int i = 0;i < N;i++){
            dist[i] = min(dist[i], dist[v] + graph[v][i]);
        }
    }
    return dist[0];
}
main(){
    int xs,ys,xg,yg;
    cin >> xs >> ys >> xg >> yg >> N;
    N += 2;
    vector<int>x(N),y(N),r(N);
    x[0] = xs;y[0] = ys;
    x[1] = xg;y[1] = yg;
    r[0] = r[1] = 0;
    for(int i = 2;i < N;i++)cin >> x[i] >> y[i] >> r[i];

    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            int dx = x[i] - x[j],dy = y[i] - y[j];
            double dist = sqrt(1.*dx*dx + 1.*dy*dy);
            graph[i][j] = graph[j][i] = max(0.0,dist - r[i] - r[j]);
        }
    }
    printf("%.10lf\n",dijkstra(1));
}
