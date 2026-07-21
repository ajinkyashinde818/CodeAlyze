#include<iostream>
#include<cstdio>
#include<string>
#include<cfloat>
#include<algorithm>
#include<cmath>
#include<vector>
#include<stack>
#include<climits>
#include<cstring>
#include<queue>
#include<map>
#include<functional>
using namespace std;

const int mod = 1e9+7;
const double INFDBL = DBL_MAX/2;
typedef long long ll;
typedef unsigned long long ull;

struct Circle{
    double x, y, r;
    Circle(double x, double y, double r): x(x), y(y), r(r) {}
};

struct Edge{
    int to;
    double weight;
    Edge(int to, double weight): to(to), weight(weight) {}
};

struct TmpDist{
    int vertex;
    double dist;
    TmpDist(int vertex, double dist): vertex(vertex), dist(dist) {}
    bool operator< (const TmpDist& right)const{
        return dist > right.dist;
    }
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

vector<double> dijkstra(Graph &G, int r){
    int V = G.size();
    vector<double> dist(V, INFDBL);
    priority_queue<TmpDist> pq;
    vector<bool> check(V, false);
    TmpDist init(r, 0);
    pq.push(init);
    while(!pq.empty()){
        TmpDist td = pq.top();pq.pop();
        int now = td.vertex;
        if(!check[now]){
            check[now] = true;
            dist[now] = td.dist;
            for (int i=0;i<G[now].size();i++){
                if(dist[G[now][i].to] > td.dist + G[now][i].weight){
                    TmpDist tdCandidate(G[now][i].to, td.dist + G[now][i].weight);
                    pq.push(tdCandidate);
                }
            }
        }
    }
    return dist;
}

double CosmicRays(double xs, double ys, double xt, double yt, vector<Circle> &circles){
    int N = circles.size();
    Graph G(N+2);
    for(int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if(i==j) continue;
            Circle c1 = circles[i];
            Circle c2 = circles[j];
            double centerDist = sqrt((c1.x - c2.x)*(c1.x - c2.x) + (c1.y - c2.y)*(c1.y - c2.y));
            Edge e(j, max(0.0, centerDist - (c1.r + c2.r)));
            G[i].push_back(e);
        }
    }
    for(int i=0;i<N;i++){
        Circle c = circles[i];
        double centerDistS = sqrt((c.x - xs)*(c.x - xs)+(c.y - ys)*(c.y - ys));
        double centerDistT = sqrt((c.x - xt)*(c.x - xt)+(c.y - yt)*(c.y - yt));
        Edge es1(i, max(0.0, centerDistS - c.r));
        Edge es2(N, max(0.0, centerDistS - c.r));
        Edge et1(i, max(0.0, centerDistT - c.r));
        Edge et2(N+1, max(0.0, centerDistT - c.r));
        G[N].push_back(es1);
        G[i].push_back(es2);
        G[N+1].push_back(et1);
        G[i].push_back(et2);
    }
    double stDist = sqrt((xs - xt)*(xs - xt)+(ys - yt)*(ys - yt));
    Edge e1(N, stDist);
    Edge e2(N+1, stDist);
    G[N+1].push_back(e1);
    G[N].push_back(e2);
    /*
    for (int i=0;i<N+2;i++){
        cout << endl;
        if(i<N) cout << i << endl;
        if(i==N) cout << "s" << endl;
        if(i==N+1) cout << "t" <<  endl;
        for (int j=0;j<G[i].size();j++){
            cout << "to: " << G[i][j].to << " dist: " << G[i][j].weight << endl;
        }
    }
    */
    vector<double> dist = dijkstra(G, N);
    return dist[N+1];
}

int main(){
    double xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;
    int N;
    cin >> N;
    vector<Circle> circles;
    double x, y, r;
    for(int i=0;i<N;i++){
        cin >> x >> y >> r;
        Circle c(x, y, r);
        circles.push_back(c);
    }
    printf("%.10f\n", CosmicRays(xs, ys, xt, yt, circles));
    return 0;
}
