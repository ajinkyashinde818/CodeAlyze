#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
using ll = long long int;
using P = pair<int, int>;

const int MAX_V = 1e6 + 10;
const double INF = 4 * 1e9;
struct edge{
    int to;
    double cost;
};
vector<edge> graph[MAX_V];
vector<double> d(MAX_V);

void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P>> que;
    fill(d.begin(), d.end(), INF);
    d[s] = 0;
    que.push(P(0, s));

    while(!que.empty()){
        P p = que.top(); que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int i=0; i<(int)graph[v].size(); i++){
            edge e = graph[v][i];
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main() {
    int xs, ys, xt, yt; cin >> xs >> ys >> xt >> yt;
    int n; cin >> n;
    vector<vector<double>> nodes;
    for(int i=0; i<n; i++){
        double xn, yn, rn; cin >> xn >> yn >> rn;
        nodes.push_back(vector<double>{xn, yn, rn});
    }
    double dx = xt - xs;
    double dy = yt - ys;
    double distance = sqrt(dx * dx + dy * dy);
    edge e1; e1.to = 0; e1.cost = distance;
    graph[n+1].push_back(e1); 
    edge e2; e2.to = n+1; e2.cost = distance;
    graph[0].push_back(e2); 
    for(int i=0; i<n; i++){
        double dx = nodes[i][0] - xs;
        double dy = nodes[i][1] - ys;
        double distance = max(0.0, sqrt(dx * dx + dy * dy) - nodes[i][2]);
        if(i+1 != 0){
            edge e1; e1.to = 0; e1.cost = distance;
            graph[i+1].push_back(e1); 
            edge e2; e2.to = i+1; e2.cost = distance;
            graph[0].push_back(e2); 
        }
        dx = nodes[i][0] - xt;
        dy = nodes[i][1] - yt;
        distance = max(0.0, sqrt(dx * dx + dy * dy) - nodes[i][2]);
        if(i+1 != n+1){
            edge e1; e1.to = n+1; e1.cost = distance;
            graph[i+1].push_back(e1); 
            edge e2; e2.to = i+1; e2.cost = distance;
            graph[n+1].push_back(e2); 
        }
        for(int j=i+1; j<n; j++){
            dx = nodes[i][0] - nodes[j][0];
            dy = nodes[i][1] - nodes[j][1];
            distance = max(0.0, sqrt(dx * dx + dy * dy) - nodes[i][2] - nodes[j][2]);
            edge e1; e1.to = j+1; e1.cost = distance;
            graph[i+1].push_back(e1); 
            edge e2; e2.to = i+1; e2.cost = distance;
            graph[j+1].push_back(e2); 
        }
    }
    // for(auto& v:graph){
    //     for(auto& w:v){
    //         cout << w.to << " " << w.cost << endl;
    //     }
    // }

    dijkstra(0);
    // for(int i=0; i<10; i++){
    //     cout << d[i] << " ";
    // }
    // cout << endl;
    cout << setprecision(12);
    cout << d[n+1] << endl;

    return 0;
}
