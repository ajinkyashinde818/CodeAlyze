#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <array>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <utility>
#include <functional>
#include <random>

using namespace std;
using lli = long long int;
template<class T, class U> void init_n(vector<T>& v, size_t n, U x) 
{ v = vector<T>(n, x); }
template<class T> void init_n(vector<T>& v, size_t n) { init_n(v, n, T()); }
template<class T> void read_n(vector<T>& v, size_t n, size_t o = 0)
{ v = vector<T>(n+o); for (lli i=o; i<n+o; ++i) cin >> v[i]; }
template<class T> void read_n(T a[], size_t n, size_t o = 0)
{ for (lli i=o; i<n+o; ++i) cin >> a[i]; }
template<class T> T gabs(const T& x) { return max(x, -x); }
#define abs gabs

struct Point {
  lli x, y, r;
};

lli n;
Point p[1003];
double mat[1003][1003];
double dist[1003];
bool fix[1003];

int main() {
  cin >> p[0].x >> p[0].y >> p[1].x >> p[1].y >> n;
  p[0].r = p[1].r = 0;
  for (lli i=0; i<n; ++i) {
    lli j=i+2;
    cin >> p[j].x >> p[j].y >> p[j].r;
  }
  lli m = n+2;

  for (lli i=0; i<m; ++i) {
    for (lli j=i+1; j<m; ++j) {
      lli dx = p[i].x-p[j].x, dy = p[i].y-p[j].y;
      double d = sqrt(double(dx*dx + dy*dy));
      mat[i][j] = mat[j][i] = max(0.0, d-p[i].r-p[j].r);
    }
  }

  using P = pair<double, lli>;
  priority_queue<P, vector<P>, greater<P>> pq;
  pq.emplace(0.0, 0);
  fill(&dist[0], &dist[1002], 1e18);
  dist[0] = 0.0;

  while (!pq.empty()) {
    P p = pq.top(); pq.pop();
    double d = p.first; lli v = p.second;
    if (fix[v]) continue;
    fix[v] = true;
    dist[v] = d;
    for (lli u=0; u<m; ++u) {
      if (fix[u]) continue;
      double e = d + mat[v][u];
      if (e < dist[u]) {
        pq.emplace(e, u);
      }
    }
  }

  printf("%.15lf\n", dist[1]);
  return 0;
}
