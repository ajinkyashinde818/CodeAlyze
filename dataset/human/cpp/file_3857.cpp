#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
using namespace std;
using ll = long long;

class range {private: struct I{int x;int operator*(){return x;}bool operator!=(I& lhs){return x<lhs.x;}void operator++(){++x;}};I i,n;
public:range(int n):i({0}),n({n}){}range(int i,int n):i({i}),n({n}){}I& begin(){return i;}I& end(){return n;}};

#include <complex>
typedef double ld;
typedef complex<ld> P;

struct C {
  P p; ld r;
  C() {}
  C(P p, ld r) : p(p), r(r) {}
};

P getp() { ld x, y; cin >> x >> y; return P(x, y); }

double d[1020][1020];

int main() {
  P start = getp();
  P goal = getp();
  int N; cin >> N;
  vector<C> vc(N + 2);
  vc[0] = C(start, 0);
  vc[1] = C(goal, 0);

  for (int i : range(N)) {
    vc[i + 2].p = getp();
    double r; cin >> r;
    vc[i + 2].r = r;
  }

  for (int i : range(N + 2))
  for (int j : range(N + 2)) {
    d[i][j] = max(0.0, abs(vc[i].p - vc[j].p) - vc[i].r - vc[j].r);
  }

  priority_queue<pair<double, int>> q;
  q.push({0.0, 0});

  vector<char> vis(N + 2);
  while (!q.empty()) {
    double curr_cost = -q.top().first;
    int idx = q.top().second;
    q.pop();
    if (vis[idx]) continue;
    vis[idx] = 1;

    if (idx == 1) {
      printf("%.14f\n", curr_cost);
      break;
    }

    for (int to : range(N + 2)) {
      if (vis[to]) continue;
      q.push(make_pair(-(curr_cost + d[idx][to]), to));
    }
  }
}
