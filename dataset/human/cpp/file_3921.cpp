#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e10;

ll sx,sy,gx,gy; ll N;

vector<vector<pair<ll,double>>> to;
vector<double> to_dist;

vector<ll> x; vector<ll> y; vector<ll> r;

//to　は重みあり隣接リスト（第一成分が接続先で、第二成分が辺の重み）で
// to　は　vec<ve<cpair
// to_dist　は　各ノードへのvからの（暫定的な)最小値を保存でただのvec

void Dijkstra(ll v){
  to_dist[v] = 0.0; 
  
  priority_queue<pair<double,ll>, vector<pair<double,ll>>, greater<pair<double,ll>>> Q; 
  Q.push(make_pair(0.0,v)); 
  //キューは、暫定の重さとノードの番号を持つ priorityは第一成分に適用、つまり
  //暫定の値が最も小さなものから見ていく
  
  while(!Q.empty()){
    //行きについてまずは調べる
    pair<double,ll> p = Q.top(); Q.pop();
    ll s = p.first; ll t = p.second; //sが重さ、tが番号
    if( to_dist[t] < s){ continue;}
    else{
      //t-ノードから繋がる全てのノードについて、もしto_dist[t] + to[t][]より大きければ更新
      for(auto ne: to[t]){
        ll x = ne.first;  double y = ne.second;
        //firstが隣接するノード、secondがそこまでの距離
        if( to_dist[x] > to_dist[t] + y){
          to_dist[x] = to_dist[t] + y; Q.push(make_pair( to_dist[x], x));}}}}

  
}

int main(){

  cin >> sx >> sy >> gx >> gy;
  
  cin >> N; x.resize(N+2); y.resize(N+2); r.resize(N+2); to.resize(N+2);
  to_dist = vector<double> (N+2, INF);
  
  for(ll i = 0; i < N; i++){
    cin >> x[i] >> y[i] >> r[i];}
  
  x[N] = sx; y[N] = sy; x[N+1] = gx; y[N+1] = gy;
  r[N] = 0; r[N+1] = 0;
  //startを(sx,sy)、goalを(gx,gy)とおく
 
  
  for(ll i = 0; i <=N+1; i++){
    for(ll j = 0; j <=N+1; j++){
      //iとjの間をundirectedに結ぶ
      if( i != j){
        double d = max( (double)sqrt(pow(x[j]-x[i],2.0)+pow(y[j]-y[i],2.0))-(double)(r[i]+r[j]),0.0); 
       
        to[i].push_back(make_pair(j,d));}
    }
  }
  
  
    
      Dijkstra(N);
      
      cout << fixed << setprecision(10) << to_dist[N+1] << endl;
  
  
      
      return 0;}
