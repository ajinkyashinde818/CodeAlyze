#include <bits/stdc++.h>
using namespace std;
const double INF = 1e12;

// computational complexity : O(E*logV)

struct edge{ int to; double cost; };

int V,E;// number of (vertices, edges)
vector<vector<edge>> graph;
vector<double> d;// shortest distances

void Dijkstra(int s){// s = starting point
    priority_queue<
        pair<double, int>// temporarily keeping (shortest distance, vertex)
        , vector<pair<double, int>>, greater<pair<double, int>>// shorter ones first
    > pq;

    // initialize (INF)
    for(int i=0; i<V; i++){
        d[i] = INF;
    }
    d[s] = 0;
    pq.push({0,s});

    // search
    pair<double, int> current;// (shortest-distance confirmed, vertex)
    while(!pq.empty()){
        current = pq.top(); pq.pop();

        int v = current.second;
        if(d[v] < current.first){
            continue;// ignore (not the shortest path)
        }
        // else (need to check)
        for(edge e : graph[v]){// adjacent nodes
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;// update minimum cost
                pq.push({d[e.to], e.to});
            }
        }
    }
}

struct circle{ int x, y, r; };

int main(){
    int xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;

    cin >> V;
    V += 2;
    graph.resize(V);
    d.resize(V);

    vector<circle> barrier(V);
    barrier[0]   = {xs, ys, 0};
    barrier[V-1] = {xt, yt, 0};
    for(int i=1; i<=V-2; i++){
        cin >> barrier[i].x >> barrier[i].y >> barrier[i].r;
    }

    for(int i=0; i<V; i++){
        for(int j=i+1; j<V; j++){
            long long int xi = barrier[i].x;
            long long int yi = barrier[i].y;
            long long int ri = barrier[i].r;
            long long int xj = barrier[j].x;
            long long int yj = barrier[j].y;
            long long int rj = barrier[j].r;

            long long int dist = (xj - xi) * (xj - xi) + (yj - yi) * (yj - yi);

            double w = max(0., sqrt(dist) - ri - rj);
            graph[i].push_back({j, w});
            graph[j].push_back({i, w});
            //cout << i << " " << j << " " << w << endl;
        }
    }

    Dijkstra(0);
    cout << fixed << setprecision(12) << d[V-1] << endl;
    return 0;
}
