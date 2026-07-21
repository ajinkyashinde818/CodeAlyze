#include<bits/stdc++.h>
using namespace std;
const int nmax=1005;
struct edge{int to;long double cost;};
vector<edge> tree[nmax];
long double d[nmax];
int n;
void dijkstra(int s){
  priority_queue<pair<long double,int>,vector<pair<long double,int>>,greater<pair<long double,int>>> pq;
  d[s]=0;
  pq.push(make_pair(0,s));
  while(!pq.empty()){
    pair<long double,int> p=pq.top();
    pq.pop();
    int v=p.second;
    if(d[v]<p.first){
      continue;
    }
    for(auto x:tree[v]){
      edge e=x;
      if(d[e.to]>d[v]+e.cost){
        d[e.to]=d[v]+e.cost;
        pq.push(make_pair(d[e.to],e.to));
      }
    }
  }
}
int main(){
  long double xs,ys,xt,yt;cin >> xs >> ys >> xt >> yt;
  int n;cin >> n;
  vector<long double> x(n+2),y(n+2),r(n+2);
  x[0]=xs,y[0]=ys,x[n+1]=xt,y[n+1]=yt;
  r[0]=0,r[n+1]=0;
  for(int i=1;i<=n;i++){
    cin >> x[i] >> y[i] >> r[i];
  }
  for(int i=0;i<=n+1;i++){
    d[i]=1e15;
  }
  for(int i=0;i<=n;i++){
    for(int j=i+1;j<=n+1;j++){
      long double dis=max((long double)0,sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))-r[i]-r[j]);
      tree[i].push_back(edge{j,dis});
      tree[j].push_back(edge{i,dis});
    }
  }
  dijkstra(0);
  cout << fixed << setprecision(15) << d[n+1] << endl;
}
