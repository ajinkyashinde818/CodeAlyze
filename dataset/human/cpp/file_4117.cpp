#include<bits/stdc++.h>
using namespace std;
typedef pair<double, int> PD;

struct edge{int to; double cost;};
const int MAX_N = 1005;
const double INF = 1e12;
int N;
double x[MAX_N], y[MAX_N], r[MAX_N], dist[MAX_N];
vector<edge> E[MAX_N];

void dijkstra(int s){
    fill(dist, dist+MAX_N, INF); dist[s] = 0.0;
    priority_queue<PD, vector<PD>, greater<PD>> pq; pq.push(PD(0.0, s));

    while(pq.size()){
        PD p = pq.top(); pq.pop();
        int v = p.second;
        if(dist[v]<p.first) continue;
        for(edge e : E[v]){
            if(dist[v]+e.cost<dist[e.to]){
                dist[e.to] = dist[v] + e.cost;
                pq.push(PD(dist[e.to], e.to));
            }
        }
    }
}

int main(){
    int xt, yt; cin >> x[0] >> y[0] >> xt >> yt;
    cin >> N;
    x[N+1] = xt; y[N+1] = yt;
    for(int i=1;i<=N;i++) cin >> x[i] >> y[i] >> r[i];

    for(int i=0;i<=N+1;i++){
        for(int j=i+1;j<=N+1;j++){
            double dist = sqrt(pow(x[j]-x[i], 2)+pow(y[j]-y[i], 2)) - r[i] - r[j];
            if(dist<=(double)0) dist = 0.0;
            edge e1; e1.to = j; e1.cost = dist;
            edge e2; e2.to = i; e2.cost = dist;
            E[i].push_back(e1); E[j].push_back(e2);
        }
    }

    dijkstra(0);

    printf("%.12lf\n", dist[N+1]);
    return 0;
}
