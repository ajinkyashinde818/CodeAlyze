#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iomanip>
using namespace std;
typedef long double ld;
typedef pair<ld, int> P;
struct edge{
    int to;
    ld cost;
    edge(int a, ld b){
        to=a;
        cost=b;
    }
};
struct D{
    vector<edge> G[1002];
    ld d[1002],INF=1e18;

    void AddEdge(int from, int to, ld cost){
        G[from].push_back(edge(to, cost));
    }

    void dijkstra(int n, int s){
        priority_queue<P, vector<P>, greater<P> > q;
        fill(d,d+n+1,INF);
        d[s]=0;
        q.push(P(0,s));
        while(!q.empty()){
            P p=q.top();
            q.pop();
            int v=p.second;
            if(d[v]<p.first)continue;
            for(int i=0;i<G[v].size();i++){
                edge e=G[v][i];
                if(d[e.to]>d[v]+e.cost){
                    d[e.to]=d[v]+e.cost;
                    q.push(P(d[e.to],e.to));
                }
            }
        }
    }
};


int main(void){
    int n;
    ld x[1002],y[1002],r[1002];
    D d;
    r[0]=r[1]=0;
    cin>>x[0]>>y[0]>>x[1]>>y[1]>>n;
    for(int i=2;i<n+2;i++){
        cin>>x[i]>>y[i]>>r[i];
    }
    for(int i=0;i<n+2;i++){
        d.AddEdge(i, i, (ld)0);
        for(int j=i+1;j<n+2;j++){
            ld t=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
            ld u=max((ld)0, t-r[i]-r[j]);
            d.AddEdge(i, j, u);
            d.AddEdge(j, i, u);
        }
    }
    d.dijkstra(n+2, 0);
    cout<<setprecision(20)<<d.d[1]<<endl;
}
