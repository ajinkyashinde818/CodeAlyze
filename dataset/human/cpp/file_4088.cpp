#include "bits/stdc++.h"
using namespace std;
using ll =long long;
using ld = long double;
using P =pair<ld,int>;

struct myCircle{
    ld x,y,r;
    myCircle(){}
    myCircle(ld xa, ld ya, ld ra) : x(xa),y(ya),r(ra){}
};
using Circles=vector<myCircle>;

ld calc(myCircle p,myCircle q){
    ld dif=(p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y);
    if(dif<=(p.r+q.r)*(p.r+q.r)) return 0;
    else return sqrt(dif)-p.r-q.r;
}

struct Edge{
    using Cost = ld;
    int to;
    Cost cost;
    Edge(int t,Cost c) : to(t),cost(c){}
};
using  Graph = vector<vector<Edge>>;

vector<ld> dijkstra(const Graph &g,int s){
   vector<ld> d(g.size(),1e30);
   d[s]=0;
   priority_queue<P,vector<P>,greater<P>> que;
   que.push(P(0,s));
   while(!que.empty()){
       ld dist=que.top().first;
       int v=que.top().second;
       que.pop();
       if(d[v]<dist)continue;
       for(const auto &e: g[v]){
           if(d[e.to]<=d[v]+e.cost) continue;
           d[e.to]=d[v]+e.cost;
           que.push(P(d[e.to],e.to));
       }
   }
   return d;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

    ld xs,ys,xt,yt;cin>>xs>>ys>>xt>>yt;
    int n;cin>>n;
    Circles barrier(n+2);
    Graph g(n+2);
    barrier[0]=myCircle(xs,ys,0.0);
    barrier[n+1]=myCircle(xt,yt,0.0);
    for(int i=1;i<=n;i++){
        ld xi,yi,ri;cin>>xi>>yi>>ri;
        barrier[i]=myCircle(xi,yi,ri);
    }
    for(int i=0;i<n+2;i++){
        for(int j=0;j<n+2;j++){
            ld tmp=calc(barrier[i],barrier[j]);
            g[i].push_back(Edge(j,tmp));
            g[j].push_back(Edge(i,tmp));
        }
    }
    vector<ld> dist=dijkstra(g,0);
    cout<<fixed<<setprecision(10)<<dist[n+1]<<endl;
}
