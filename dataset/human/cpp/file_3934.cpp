#include <iostream>
#include <cmath>
#include <queue>
#include <iomanip>
#include <cfloat>
using namespace std;
typedef pair<double, int> P;

int xs, ys, xt, yt;
int N;
int x[1000], y[1000], r[1000];
struct edge {int to; double cost;};
vector<edge> G[1002];
double d[1002];

void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P>> que;
    fill(d, d+N+2, DBL_MAX);
    d[s] = 0.0;
    que.push(P(0.0, s));
    while(!que.empty()){
        P p = que.top(); que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int i=0; i<G[v].size(); i++){
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

double getCost(int x1, int y1, int r1, int x2, int y2, int r2){
    double temp = sqrt(pow(x1-x2, 2.0) + pow(y1-y2, 2.0));
    return max(0.0, temp - r1 - r2);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
    cin >> xs >> ys >> xt >> yt;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> x[i] >> y[i] >> r[i];
    }
    for(int i=0; i<N; i++){
        double c = getCost(xs, ys, 0.0, x[i], y[i], r[i]);
        G[0].push_back(edge{i+1, c});
        G[i+1].push_back(edge{0, c});
        c = getCost(xt, yt, 0.0, x[i], y[i], r[i]);
        G[N+1].push_back(edge{i+1, c});
        G[i+1].push_back(edge{N+1, c});
    }
    double c = getCost(xs, ys, 0.0, xt, yt, 0.0);
    G[0].push_back(edge({N+1, c}));
    G[N+1].push_back(edge({0, c}));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            double c = getCost(x[i], y[i], r[i], x[j], y[j], r[j]);
            G[i+1].push_back(edge{j+1, c});
            G[j+1].push_back(edge{i+1, c});
        }
    }
    dijkstra(0);
    cout << setprecision(32) << d[N+1] << endl;


	return 0;
}
