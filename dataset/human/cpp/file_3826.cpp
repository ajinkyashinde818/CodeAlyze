#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;
typedef vector<string> vs;

double d[1005][1005];

double p2(double x) {
  return x * x;
}

int main() {
  vi x(2), y(2), r(2);
  int n;
  cin >> x[0] >> y[0] >> x[1] >> y[1] >> n;
  for (int i = 0; i < n; ++i) {
    int a,b,c;
    cin >> a >> b >> c;
    x.push_back(a);
    y.push_back(b);
    r.push_back(c);
  }
  n += 2;
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    d[i][j] = max(0., sqrt(p2(x[i] - x[j]) + p2(y[i] - y[j])) - r[i] - r[j]);
  }
  vd dist(n, 1e18);
  dist[0] = 0;
  set<pdi> q;
  q.insert(pdi(0, 0));
  while (!q.empty()) {
    int v = q.begin()->second;
    q.erase(q.begin());
    for (int i = 0; i < n; ++i) {
      double nd = dist[v] + d[i][v];
      if (nd < dist[i]) {
        q.erase(pdi(dist[i], i));
        dist[i] = nd;
        q.insert(pdi(dist[i], i));
      }
    }
  }
  printf("%.15lf\n", dist[1]);
  return 0;
}
