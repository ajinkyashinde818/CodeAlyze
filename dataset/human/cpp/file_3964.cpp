#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <iomanip>

using namespace std;

typedef pair<double, int> P;

double G[1002][1002];
double d[1002];

const double INF = 1e+20;

int N;

void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P>> que;
    fill(d, d+N+2, INF);
    d[s] = 0;
    que.push(P(s, 0));
    while(!que.empty()){
        P p = que.top();que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int i = 0; i <= N+1; i++){
            double e = G[v][i];
            if(d[v] + e < d[i] && v != i){
                d[i] = d[v] + e;
                que.push(P(d[i], i));
            }
        }
    }
}


int main(){
    double xs, ys, xt, yt;
    double x[1002];
    double y[1002];
    double r[1002] = {0};
    cin >> xs >> ys >> xt >> yt;
    cin >> N;
    x[0] = xs;
    y[0] = ys;
    x[N+1] = xt;
    y[N+1] = yt;
    for(int i = 1; i <= N; i++){
        cin >> x[i] >> y[i] >> r[i];
    }
    for(int i = 0; i <= N+1; i++){
        for(int j = 0; j < i; j++){
            double l = sqrt((double)((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))) - (r[i]+r[j]);
            l = max(0.0, l);
            G[i][j] = l;
            G[j][i] = l;
            //cout << l << ' ';
        }
    }
    dijkstra(0);
    std::cout << std::fixed;
    cout << std::setprecision(15) << d[N+1] << endl;
}
