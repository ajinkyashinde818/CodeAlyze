// includes
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>
#include <climits>
#include <bitset>

// macros
#define ll long long int
#define pb push_back
#define mk make_pair
#define pq priority_queue
#define FOR(i, a, b) for(int i=(a); i<(b);++i)
#define rep(i, n) FOR(i, 0, n)

using namespace std;

//  types
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
typedef pair<ll, ll> Pll;
 
// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;

// solve

template <typename T>
struct Graph_ {
  int n;
  vector<vector<pair<int, T> > > edge;
  vector<T> dis;
  Graph_(int ns) {
    n = ns;
    edge.resize(n);
    dis.resize(n);
  }
  void dijkstra(int s){
    dijkstra(s, 0);
  }
  T dijkstra(int s, int t){
    // initialize
    fill(dis.begin(), dis.end(), -1);
    vector<bool> used;
    used.resize(n);
    fill(used.begin(), used.end(), false);
    dis[s] = 0;
    // dijkstra
    priority_queue<pair<T, int>, vector<pair<T, int> >, greater<pair<T, int> > > q;
    q.push(make_pair(0, s));
    while(!q.empty()){
      pair<T, int> p = q.top(); q.pop();
      int at = p.second;
      T distance = p.first;
      if(used[at])continue;
      used[at] = true;
      for(auto itr = edge[at].begin(); itr != edge[at].end(); ++itr){
        int to = (*itr).first;
        T cost = (*itr).second;
        if(used[to])continue;
        if(dis[to] == -1 || dis[to] > distance + cost){
          q.push(make_pair(distance + cost, to));
          dis[to] = distance + cost;
        }
      }
    }
    return dis[t];
  }
  void adde(int at, int to, T cost){
    edge[at].push_back(make_pair(to, cost));
  }
  [[deprecated("This function takes O(edge[at].size()).")]]
  void remove(int at, int to){
    int index = -1;
    for(int i = 0; i < edge[at].size(); i++){
      if(edge[at][i].first == to){
        index = i;
        break;
      }
    }
    edge[at].erase(edge[at].begin() + index);
  }
};

typedef struct Graph_<int> GraphI;
typedef struct Graph_<ll> GraphL;
typedef struct Graph_<double> GraphD;

vector<double>x, y, r;

int main(int argc, char const* argv[])
{
  double xs, ys, xt, yt;
  cin >> xs >> ys >> xt >> yt;
  int n;
  cin >> n;
  rep(i, n){
    double a, b, c;
    cin >> a >> b >> c;
    x.pb(a);
    y.pb(b);
    r.pb(c);
  }
  GraphD graph(n + 2);
  graph.adde(0, n+1, sqrt((xs-xt)*(xs-xt)+(ys-yt)*(ys-yt)));
  FOR(i, 1, n+1){
    graph.adde(0, i, max(0., sqrt((x[i-1]-xs)*(x[i-1]-xs)+(y[i-1]-ys)*(y[i-1]-ys))-r[i-1]));
    graph.adde(i, n+1, max(0., sqrt((x[i-1]-xt)*(x[i-1]-xt)+(y[i-1]-yt)*(y[i-1]-yt))-r[i-1]));
  }
  FOR(i, 1, n+1){
    FOR(j, i+1, n+1){
      graph.adde(i, j, max(0., sqrt((x[i-1]-x[j-1])*(x[i-1]-x[j-1])+(y[i-1]-y[j-1])*(y[i-1]-y[j-1]))-r[i-1]-r[j-1]));
      graph.adde(j, i, max(0., sqrt((x[i-1]-x[j-1])*(x[i-1]-x[j-1])+(y[i-1]-y[j-1])*(y[i-1]-y[j-1]))-r[i-1]-r[j-1]));
    }
  }
  cout << setprecision(12);
  cout << graph.dijkstra(0, n+1) << endl;
	return 0;
}
