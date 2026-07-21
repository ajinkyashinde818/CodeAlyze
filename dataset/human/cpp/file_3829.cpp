#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
const int mx=1e3+10;
const ld inf=1e16;
double x[mx],y[mx],r[mx];
vector<int>g[mx];
vector<ld>w[mx];
ld ds[mx];
struct node{
  int u;
  ld w;
  node(int u,ld w):u(u),w(w){}
  bool operator <(node n)const{
    return w>n.w;
  }
};
void dij(int u){
  fill(ds,ds+mx,inf);
  priority_queue<node>q;
  q.push(node(u,0ll));
  ds[u]=0;
  while(!q.empty()){
    u=q.top().u;
    ld wu=q.top().w;
    q.pop();
    if(ds[u]!=wu)continue;
    for(int i=0;i<int(g[u].size());i++){
      int v=g[u][i];
      ld bet=wu+w[u][i];
      if(bet<ds[v]){
        ds[v]=bet;
        q.push(node(v,bet));
      }
    }
  }
}

int main(){
  int n;
  double xs,ys,xt,yt;
  scanf("%lf %lf %lf %lf %d",&xs,&ys,&xt,&yt,&n);
  for(int i=0;i<n;i++)
    scanf("%lf %lf %lf",x+i,y+i,r+i);  
  int s=n,t=n+1;
  x[s]=xs,y[s]=ys,r[s]=0;
  x[t]=xt,y[t]=yt,r[t]=0;
  for(int i=0;i<n+2;i++){
    for(int j=i+1;j<n+2;j++){
      ld d2=powl(x[i]-x[j],2)+powl(y[i]-y[j],2);
      ld d=sqrtl(d2);
      if(d2>powl(r[i]+r[j],2))d-=r[i]+r[j];      
      else d=0;
      g[i].push_back(j);
      g[j].push_back(i);
      w[i].push_back(d);
      w[j].push_back(d);
    }    
  }
  dij(s);
  cout<<setprecision(15)<<fixed<<ds[t]<<endl;
  return 0;
}
