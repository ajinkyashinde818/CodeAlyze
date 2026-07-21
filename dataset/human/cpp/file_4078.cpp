#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>
#include<iomanip>
#include<utility>
#include<cmath>
#include<set>
#include<list>
#include<string>
#include<queue>
#include<stack>
#include<deque>
#include<map>
#include<set>
#include<cstring>
#include<iterator>
#include<bitset>
#include<assert.h>
//#include<unistd.h>
//#include<chrono>
//#include<time.h>
//#include<windows.h>
using namespace std;
 
//#define int ll
typedef long long ll;
static const int MOD = 1000000007;
//static const int INF = 2147483647;
//static const long long INF = 9223372000000000000;
//static const long long INF = 9223372000000000000/2;
//static const int INF = 1000010000;
//int dx4[4] = {0,1,0,-1}, dy4[4] = {-1,0,1,0};
//int dx5[5] = {-1,0,0,0,1}, dy5[5] = {0,-1,0,1,0};
//int dx8[8] = {-1,0,1,1,1,0,-1,-1}, dy8[8] = {1,1,1,0,-1,-1,-1,0};
//int dx9[9] = {-1,0,1,1,1,0,-1,-1,0}, dy9[9] = {1,1,1,0,-1,-1,-1,0,0};
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define MT make_tuple
#define FI first
#define SE second
#define NP next_permutation
#define PQ priority_queue
#define UB upper_bound
#define LB lower_bound
#define SZ(a) int((a).size())
#define LEN(a) int((a).length())
#define SORT(c) sort((c).begin(),(c).end())
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REP1(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREP1(i,x) for(int i=((int)(x));i>0;i--)
#define ALL(x) (x).begin(),(x).end()
#define YESNO(x) puts((x)?"YES":"NO")

template< typename T >
struct edge
{
  int src, to;
  T cost;
 
  edge(int to, T cost) : src(-1), to(to), cost(cost) {}
 
  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}
 
  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;

template< typename T >
vector< T > dijkstra(WeightedGraph< T > &g, int s)
{
  const auto INF = numeric_limits< T >::max();
  vector< T > dist(g.size(), INF);

  using Pi = pair< T, int >;
  priority_queue< Pi, vector< Pi >, greater< Pi > > que;
  dist[s] = 0;
  que.emplace(dist[s], s);
  while(!que.empty()) {
    T cost;
    int idx;
    tie(cost, idx) = que.top();
    que.pop();
    if(dist[idx] < cost) continue;
    for(auto &e : g[idx]) {
      auto next_cost = cost + e.cost;
      if(dist[e.to] <= next_cost) continue;
      dist[e.to] = next_cost;
      que.emplace(dist[e.to], e.to);
    }
  }
  return dist;
}


signed main(){
    int sx,sy,gx,gy;
    cin >> sx >> sy >> gx >> gy;
    int n;
    cin >> n;
    pair<pair<int,int>,int> z[1145];
    z[0] = MP(MP(sx,sy),0);
    z[n+1] = MP(MP(gx,gy),0);

    REP1(i,n){
        int x,y,r;
        cin >> x >> y >> r;
        z[i] = MP(MP(x,y),r);
    }

    WeightedGraph< double > g(n+2);
    REP(i,n+2){
        FOR(j,i+1,n+2){
            double dist = 
                hypot(double(abs(z[i].FI.FI-z[j].FI.FI)),
                      double(abs(z[i].FI.SE-z[j].FI.SE)))
                - double(z[i].SE+z[j].SE);
            if(dist<0) dist = 0;
            g[i].EB(j,dist);
            g[j].EB(i,dist);
        }
    }

    auto cost = dijkstra(g,0);
    printf("%.15lf\n",cost[n+1]);

    return 0;
}
