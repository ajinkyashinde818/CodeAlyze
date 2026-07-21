#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fst first
#define snd second
#define all(v) begin(v), end(v)
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl
#define DBL_INF 1.0e18

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
template<class T> using vv=vector<vector< T > >;

int n;
vv<double> cost;
vector<double> d;
deque<bool> used;

void dijkstra(int s) {
  d.assign(n+2, DBL_INF);
  used.assign(n+2, false);
  d[s] = 0;

  while (true) {
    int v = -1;
    rep (u, n+2) {
      if (!used[u] && (v == -1 || d[u] < d[v])) {
        v = u;
      }
    }
    if (v == -1) {
      break;
    }
    used[v] = true;
    rep (u, n+2) {
      d[u] = min(d[u], d[v] + cost[v][u]);
    }
  }
}

int main() {
  ll xs, ys, xg, yg;
  scanf("%lld %lld %lld %lld", &xs, &ys, &xg, &yg);
  scanf("%d", &n);
  cost.assign(n+2, vector<double>(n+2, 0));
  vll x(n+2), y(n+2), r(n+2);
  x[0] = xs;
  y[0] = ys;
  r[0] = 0;
  FOR (i, 1, n+1) {
    scanf("%lld %lld %lld", &x[i], &y[i], &r[i]);
  }
  x[n+1] = xg;
  y[n+1] = yg;
  r[n+1] = 0;
  rep (i, n+2) {
    FOR (j, i+1, n+2) {
      ll dx = x[i] - x[j];
      ll dy = y[i] - y[j];
      double c = max(0.0, sqrt(dx*dx + dy*dy) - r[i] - r[j]);
      cost[i][j] = cost[j][i] = c;
    }
  }
  dijkstra(0);
  printf("%.12f\n", d[n+1]);
  return 0;
}
