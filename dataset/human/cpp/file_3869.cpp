#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
typedef pair<double, int> P;

double INF = 1.0e+15;

struct edge{
    int to;
    double cost;
};

/////////////////////////////////////////////////////////////////////////

class GraphD{
public:
    int N;
    vector<double> d;
    vector<vector<edge>> G;

    GraphD(int n){
        N = n;
        d.resize(N, INF);
        G.resize(N, vector<edge>(0));
    }

    void makeEdge(int s, int t, double c){
        G[s].push_back(edge{t, c});
        G[t].push_back(edge{s, c});
    }

    void dijkstra(int s){
        fill(d.begin(), d.end(), INF);
        priority_queue<P, vector<P>, greater<P>> que;
        d[s] = 0;
        que.push(P(0, s));

        while(!que.empty()){
            P p = que.top();
            que.pop();
            int v = p.second;
            if(d[v] < p.first) continue;

            for(int i = 0; i < (int)G[v].size(); i++){
                edge e = G[v][i];
                if(d[e.to] > d[v] + e.cost){
                    d[e.to] = d[v] + e.cost;
                    que.push(P(d[e.to], e.to));
                }
            }
        }
    }

    double getCost(int t){
        return d[t];
    }
};

//////////////////////////////////////////////////////////////////////

int main(){
    double xs, ys, xt, yt;
    int N;
    cin >> xs >> ys >> xt >> yt >> N;
    double x[N], y[N], r[N];

    for(int i = 0; i < N; i++){
        cin >> x[i] >> y[i] >> r[i];
    }

    GraphD gr = GraphD(N + 2);

    //円どうしのきょり
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            double d = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
            d -= r[i] + r[j];
            d = max(0.0, d);
            gr.makeEdge(i, j, d);
        }
    }

    //sとの距離
    for(int i = 0; i < N; i++){
        double d = sqrt((x[i] - xs) * (x[i] - xs) + (y[i] - ys) * (y[i] - ys));
        d -= r[i];
        d = max(0.0, d);
        gr.makeEdge(i, N, d);
    }

    //tとの距離
    for(int i = 0; i < N; i++){
        double d = sqrt((x[i] - xt) * (x[i] - xt) + (y[i] - yt) * (y[i] - yt));
        d -= r[i];
        d = max(0.0, d);
        gr.makeEdge(i, N + 1, d);
    }

    //sとt
    gr.makeEdge(N, N + 1, sqrt((xs - xt) * (xs - xt) + (ys - yt) * (ys - yt)));

    gr.dijkstra(N);

    cout << fixed << setprecision(12) << gr.getCost(N + 1) << endl;
    return 0;
}
