#include <iostream>
#include <complex>
#include <sstream>
#include <string>
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <vector>
#include <set>
#include <limits>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
#define REP(i, j) for(int i = 0; i < (int)(j); ++i)
#define FOR(i, j, k) for(int i = (int)(j); i < (int)(k); ++i)
#define SORT(v) sort((v).begin(), (v).end())
#define REVERSE(v) reverse((v).begin(), (v).end())
typedef complex<double> P;
const double EPS = 1e-12;
#define EQ(a,b) (abs((a)-(b)) < EPS)

double cross(const P& a, const P& b) {
  return imag(conj(a)*b);
}

double dot(const P& a, const P& b) {
  return real(conj(a)*b);
}

struct L : public vector<P> {
  L(const P &a, const P &b) {
    push_back(a); push_back(b);
  }
};

struct C {
  P p; double r;
  C(const P &p, double r) : p(p), r(r) { }
};

int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > 0)   return +1;       // counter clockwise
  if (cross(b, c) < 0)   return -1;       // clockwise
  if (dot(b, c) < 0)     return +2;       // c--a--b on line
  if (norm(b) < norm(c)) return -2;       // a--b--c on line
  return 0;
}

P projection(const L &l, const P &p) {
  double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
  return l[0] + t*(l[0]-l[1]);
}

double distanceLP(const L &l, const P &p) {
  return abs(p - projection(l, p));
}


int intersectSC(const L &s, const C &c) {
  int ins = 0;
  for(int i = 0; i < 2; i++ ) {
    if (abs(s[i]-c.p)<c.r) ins++;
    else if (EQ(abs(s[i]-c.p), c.r)) return 0;
  }
  if (ins == 2) return -1;
  if (ins == 1) return 1;
  double d = distanceLP(s, c.p);
  if (d-c.r > EPS) return -1;
  P nor=(s[0]-s[1]) * P(0, 1);
  if (ccw(c.p, c.p+nor, s[0]) * ccw(c.p, c.p+nor, s[1]) < 0) return 2;
  return -1;
}

int main() {
  int N;
  while(cin >>N && N){
    vector<int> x(N), y(N), r(N);
    REP(i, N) cin >>x[i] >>y[i] >>r[i];
    int M; cin >>M;
    REP(m, M){
      int tx, ty, sx, sy; cin >>tx >>ty >>sx >>sy;
      L l = L(P(tx, ty), P(sx, sy));
      bool f = true;
      REP(n, N) if(intersectSC(l, C(P(x[n], y[n]), r[n])) >= 0) f = false;
      cout <<(f ? "Danger" : "Safe") <<endl;
    }
  }
  return 0;
}
