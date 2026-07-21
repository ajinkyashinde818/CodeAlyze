#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<double,ll> P;
typedef vector<P> vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>=(b);--i)
#define SIZE(a) int((a).size())
#define out(a) cout<<(a)<<endl;
const int INF=INT_MAX;
const int MAX = 510000;
const ll MOD = 100000000000007;
ll fac[MAX], finv[MAX], inv[MAX];
//ダイクストラ法は負の経路があるとき使えない→ベルマンフォード法
int main(){
  ll xs,ys,xt,yt;cin>>xs>>ys>>xt>>yt;
  ll v;cin>>v;
  vector<vector<double> > g(v+2,vector<double>(v+2,0));vll x(v+2),y(v+2),r(v+2,0);
  vector<double> dis(v+2,MOD);
  vb seen(v+2,false);
  rep(i,1,v+1){
    cin>>x[i]>>y[i]>>r[i];
  }
  x[0]=xs;x[v+1]=xt;y[0]=ys;y[v+1]=yt;
  rep(i,0,v+2){
    rep(j,i,v+2){
      if(i==j)continue;
      g[i][j]=g[j][i]=pow(pow(x[i]-x[j],2)+pow(y[i]-y[j],2),0.5)-r[i]-r[j];
      if(g[i][j]<0)g[i][j]=0;
      if(g[j][i]<0)g[j][i]=0;
    }
  }
  priority_queue<P,vector<P>,greater<P> > pq;
  dis[0]=0;
  pq.push(make_pair(dis[0],0));
  while(!pq.empty()){
    P p=pq.top();
    pq.pop();
    ll from=p.second;
    if(seen[from]){continue;}
    seen[from]=true;
    if(dis[from]<p.first)continue;
    rep(i,0,v+2){
      if(dis[i]>dis[from]+g[from][i]){
        dis[i]=dis[from]+g[from][i];
        pq.push(make_pair(dis[i],i));
      }
    }
  }
  cout<<fixed<<setprecision(12)<<dis[v+1]<<endl;
}
