/*
* Welcome to my code!
*---------------------------------------------*
* author : lynmisakura(twitter : @andoreiji11)
*/
#include <iostream>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define repn for(int i = 0;i < n;i++)
#define ain(a) for(auto& i : a)cin >> i;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size()) 
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define cont continue

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using pi = pair<int,int>;
using vpi = vector<pi>;
using pl = pair<ll,ll>;
using vpl = vector<pl>;

template<class T> bool chmin(T& a,T b){if(a > b){a = b;return true;}else return false;}
template<class T> bool chmax(T& a,T b){if(a < b){a = b;return true;}else return false;}
template<class T> void print(std::vector<T> a)
{ int sz = a.size(); for(int i=0;i<a.size();i++)cout << a[i] << (i < sz-1 ? ' ' : '\n'); }
void ioboost(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}
///////////////////////////////////////////////////////////
template<class T> struct Edge{

  int to;
  T cost;

  Edge(int t = 0,T c = 1):to(t),cost(c){}

};
template<class T> struct Graph{
  
  int N,M = 0;
  vector<vector<Edge<T> > > g;

  Graph(int N):N(N),g(N,vector<Edge<T> >(0)){}

  void add_edge(int a,int b,T c = 1){
    g[a].emplace_back(b,c);
    M++;
  }

};

// last checked : 2020.5.10
template<class T> struct Dijkstra{
    
  Graph<T> G;
  vector<T> d;
  vector<int> p;

  Dijkstra(Graph<T>& G):G(G),d(G.N,1e18){}

  void solve(int s){
    d.assign(G.N,1e18);
    p.assign(G.N,-1); 

    d[s] = 0;
    using P = pair<T,int>;
    priority_queue<P,vector<P>,greater<P> > q;
    q.push({0,s});
    while(!q.empty()){
      int v = q.top().second;
      T d_v = q.top().first;
      q.pop();
      if(d_v != d[v])continue;

      for(auto edge : G.g[v]){
        if(d[v] + edge.cost < d[edge.to]){
          d[edge.to] = d[v] + edge.cost;
          p[edge.to] = v;
          q.push({d[edge.to],edge.to});
        }
      }
    }
  }
};

const double eps = 1e-14;
int n;
double sx,sy,tx,ty;
double x[1010],y[1010],r[1010];

double get_dist(int i,int j){
  return sqrt(pow(x[i] - x[j],2) + pow(y[i] - y[j],2));
}
int main(void){
  // ioboost();
  cout << fixed << setprecision(10);
  
  cin >> x[0] >> y[0] >> x[1009] >> y[1009] >> n;
  x[n+1] = x[1009],y[n+1] = y[1009];

  rep(i,n){
    cin >> x[i+1] >> y[i+1] >> r[i+1];
  }
  Graph<double> G(n+2);
  rep(i,n+2)rep(j,i){
    if(r[i] + r[j] + eps > get_dist(i,j)){
      G.add_edge(i,j,0);
      G.add_edge(j,i,0);
    }else{
      G.add_edge(i,j,get_dist(i,j) - (r[i] + r[j]));
      G.add_edge(j,i,get_dist(i,j) - (r[i] + r[j]));
    }
  }
  Dijkstra<double> D(G);
  D.solve(0);

  cout << D.d[n+1] << '\n';


}
