#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr long long MOD = 1000000007;
constexpr long long INF = 1LL << 60;
const long double PI = acosl(-1.0);
constexpr long double EPS = 1e-11;
template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
struct edge{
    long long to;
    long double cost;
};
typedef pair<ll,long double> P;
struct graph{
  ll V;
  vector<vector<edge> > G;
  vector<long double> d;

  graph(ll n){
    init(n);
  }

  void init(ll n){
    V = n;
    G.resize(V);
    d.resize(V);
    for (ll i = 0; i < V;i++){
            d[i] = INF;
        }
  }

  void add_edge(ll s, ll t, long double cost){
    edge e;
    e.to = t, e.cost = cost;
    G[s].push_back(e);
  }

  void dijkstra(ll s){
      for (ll i = 0; i < V;i++) {
          d[i] = INF;
      }
    d[s] = 0;
    priority_queue<P,vector<P>, greater<P> > que;
    que.push(P(0,s));
    while(!que.empty()){
      P p = que.top(); que.pop();
      ll v = p.second;
      if(d[v]<p.first) continue;
      for(auto e : G[v]){
        if(d[e.to]>d[v]+e.cost){
          d[e.to] = d[v]+e.cost;
          que.push(P(d[e.to],e.to));
        }
      }
    }
  }
};
long double calcdist(ll x1,ll y1,ll r1,ll x2,ll y2,ll r2){
    return max((long double)0,sqrtl((long double)(x1 - x2) * (long double)(x1 - x2) + (long double)(y1 - y2) * (long double)(y1 - y2)) - (long double)r1 - (long double)r2);
}
int main(){
    ll xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;
    ll n;
    cin >> n;
    ll x[n+2], y[n+2], r[n+2];
    for (ll i = 0; i < n;i++){
        cin >> x[i] >> y[i] >> r[i];
    }
    x[n] = xs;
    y[n] = ys;
    r[n] = 0;
    x[n + 1] = xt;
    y[n + 1] = yt;
    r[n + 1] = 0;

    graph g(n + 2);
    for (ll i = 0; i < n + 2;i++){
        for (ll j = 0; j < n + 2;j++){
            if (i == j) continue;
            g.add_edge(i,j,calcdist(x[i], y[i], r[i], x[j], y[j], r[j]));
			g.add_edge(j,i,calcdist(x[i], y[i], r[i], x[j], y[j], r[j]));
        }
    }
    g.dijkstra(n);
    long double ans = g.d[n + 1];
    cout << fixed << setprecision(10) << ans << endl;
}
