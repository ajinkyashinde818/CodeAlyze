#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <set>
#include <iomanip>
#include <deque>
#include <limits>
using namespace std;
typedef long long ll;
 
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define RREP(i,n) for(int (i)=(int)(n)-1;i>=0;i--)
#define FOREACH(i,Itr) for(auto (i)=(Itr).begin();(i)!=(Itr).end();(i)++)
#define REMOVE(Itr,n) (Itr).erase(remove((Itr).begin(),(Itr).end(),n),(Itr).end())
#define UNIQUE(Itr) sort((Itr).begin(),(Itr).end()); (Itr).erase(unique((Itr).begin(),(Itr).end()),(Itr).end())
#define LBOUND(Itr,val) lower_bound((Itr).begin(),(Itr).end(),(val))
#define UBOUND(Itr,val) upper_bound((Itr).begin(),(Itr).end(),(val))
 
template <class T> struct Dijkstra {
   struct Edge{ 
      int to;
      T cost;
      Edge(int _to, T _cost) : to(_to), cost(_cost) {}
   };
   const T INF_T = numeric_limits<T>::max();
   vector< vector<Edge> > G;
   vector<T> d;
   Dijkstra (int n) : G(n), d(n) {}
   T dist(int a) { return d[a]; }
   void add_directed_edge(int a, int b, T c) {
      G[a].push_back(Edge(b,c));
   }
   void add_undirected_edge(int a, int b, T c) {
      G[a].push_back(Edge(b,c));
      G[b].push_back(Edge(a,c));
   }
   void init(int s){
      priority_queue< pair<T,int>,vector< pair<T,int> >, greater< pair<T,int> > > que;
      for (int i=0; i<d.size(); i++) d[i] = INF_T;
      d[s] = 0;
      que.push(make_pair(0,s));
      while (!que.empty()){
         pair<T,int> p = que.top(); 
         que.pop();
         int v = p.second;
         if (d[v] < p.first) continue;
         for (int i=0; i<G[v].size(); i++) {
            Edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
               d[e.to] = d[v] + e.cost;
               que.push(make_pair(d[e.to],e.to));
            }
         }
      }
   }
}; 
 
map< pair<ll,ll>,int > v;
 
int main(){
    
    ll xs,ys,xt,yt; cin>>xs>>ys>>xt>>yt;
    ll N; cin>>N;
    vector<ll> x(N),y(N),r(N);
    REP(i,N)cin>>x[i]>>y[i]>>r[i];
    
    Dijkstra<double> inst(12000);
    REP(i,N){
        v[make_pair(x[i],y[i])]=i+1;
    }
    
    REP(i,N)REP(j,N){
        if(i!=j){
            int v1=v[make_pair(x[i],y[i])];
            int v2=v[make_pair(x[j],y[j])];
            double dist=sqrt (pow((double)abs(x[i]-x[j]),2.0)+pow((double)abs(y[i]-y[j]),2.0) );
            dist-=(r[i]+r[j]);
            dist=max(dist,0.0);
            inst.add_undirected_edge(v1,v2,dist);
        }
    }
    
    int vs=10000;
    int vt=10001;
    REP(i,N){
        int v1=v[make_pair(x[i],y[i])];
        double dist1=sqrt (pow((double)abs(x[i]-xs),2.0)+pow((double)abs(y[i]-ys),2.0) );
        dist1-=r[i];
        dist1=max(dist1,0.0);
        inst.add_undirected_edge(vs,v1,dist1);
        
        double dist2=sqrt (pow((double)abs(x[i]-xt),2.0)+pow((double)abs(y[i]-yt),2.0) );
        dist2-=r[i];
        dist2=max(dist2,0.0);
        inst.add_undirected_edge(vt,v1,dist2);
    }
    
    double distst=sqrt (pow((double)abs(xs-xt),2.0)+pow((double)abs(ys-yt),2.0) );
    inst.add_undirected_edge(vs,vt,distst);
    
    inst.init(vs);
    cout<<fixed<<setprecision(10)<<inst.dist(vt)<<endl;
    
    return 0;
}
