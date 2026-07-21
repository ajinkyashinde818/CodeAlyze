#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ld,ll> P;
ll xz[1005]={0},yz[1005]={0};
ll rz[1005]={0};
ld dist[1005][1005]={0};
ld get_dist(ll i,ll j){
  ll da=(xz[i]-xz[j])*(xz[i]-xz[j]);
  da+=(yz[i]-yz[j])*(yz[i]-yz[j]);
  ll db=(rz[i]+rz[j])*(rz[i]+rz[j]);
  if(da<=db) return 0;
  else return sqrt((ld)da)-(rz[i]+rz[j]);
}
int main(){
  ll xs,ys,xg,yg;
  cin>>xs>>ys>>xg>>yg;
  ll n;
  cin>>n;
  xz[0]=xs;
  yz[0]=ys;
  xz[n+1]=xg;
  yz[n+1]=yg;
  for(int i=1;i<=n;i++) cin>>xz[i]>>yz[i]>>rz[i];
  for(int i=0;i<=n+1;i++){
    for(int j=0;j<=n+1;j++){
      if(i!=j) dist[i][j]=get_dist(i,j);
    }
  }
  ld min_cost[1005]={0};
  bool used[1005]={false};
  used[0]=false;
  for(int i=1;i<=n+1;i++) {
    min_cost[i]=174417441744.00;
    used[i]=false;
  }
  priority_queue<P,vector<P>,greater<P>> pque;
  pque.push(P(0,0));
  while(!pque.empty()){
    P p=pque.top();
    pque.pop();
    ld cos=p.first;
    ll pos=p.second;
    if(used[pos]) continue;
    used[pos]=true;
    for(int i=0;i<=n+1;i++){
      if(i!=pos&&!used[i]){
        ld ncos=cos+dist[pos][i];
        if(ncos<min_cost[i]){
          min_cost[i]=ncos;
          pque.push(P(ncos,i));
        }
      }
    }
  }
  cout<<fixed;
  cout<<setprecision(15)<<min_cost[n+1]<<endl;
}
