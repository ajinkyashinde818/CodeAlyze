#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

using R = long double;
constexpr R pi = acos((R)-1), eps = 1e-10;

int sgn(R a) { return (a > eps) - (a < -eps); }
int sgn(R a, R b) { return sgn(a - b); }
using P = complex<R>;
istream& operator>>(istream& i, P& p) { R x, y; i >> x >> y; p = P(x, y); return i; }
ostream& operator<<(ostream& o, P p) { return o << fixed << setprecision(15) << real(p) << ' ' << imag(p); }
bool cmp(P p, P q) { return 2 * sgn(real(p), real(q)) + sgn(imag(p), imag(q)) < 0; }
bool eql(P p, P q) { return !cmp(p, q) and !cmp(q, p); }
R dot(P p, P q) { return real(conj(p) * q); }
R crs(P p, P q) { return imag(conj(p) * q); }
// -2: back, -1: cw, 0: on, 1: ccw, 2: front
int ccw(P p, P q) {
  int s = sgn(crs(p, q));
  if (s) return s;
  if (dot(p, q) < 0) return -2;
  if (dot(p, q - p) > 0) return 2;
  return 0;
}
int ccw(P o, P p, P q) { return ccw(p - o, q - o); }
struct L {
  P s, t;
  P vec() const { return t - s; }
  R abs() const { return std::abs(vec()); }
  R arg() const { return std::arg(vec()); }
};
int ccw(L s, P p) { return ccw(s.s, s.t, p); }

P proj(P p, L l) {
  P e = l.vec() / l.abs();
  return l.s + dot(p - l.s, e) * e;
}
P refl(P p, L l) { return (R)2 * proj(p, l) - p; }
R distPP(P p, P q) { return abs(q - p); }
R distPL(P p, L l) { return distPP(p, proj(p, l)); }
R distPS(P p, L s) {
  P q = proj(p, s);
  if (!ccw(s, q)) return distPP(p, q);
  return min(distPP(p, s.s), distPP(p, s.t));
}
R distLL(L l, L m) {
  if (sgn(crs(l.vec(), m.vec()))) return 0;
  return distPL(l.s, m);
}
R distLS(L l, L s) {
  if (ccw(l, s.s) * ccw(l, s.t) != 1) return 0;
  return min(distPL(s.s, l), distPL(s.t, l));
}
R distSS(L s, L t) {
  if (ccw(s, t.s) * ccw(s, t.t) <= 0 and ccw(t, s.s) * ccw(t, s.t) <= 0) return 0;
  return min({distPS(s.s, t), distPS(s.t, t), distPS(t.s, s), distPS(t.t, s)});
}
P intxn(L l, L m) {
  assert(sgn(crs(l.vec(), m.vec())));
  return l.s + crs(m.s - l.s, m.vec()) / crs(l.vec(), m.vec()) * l.vec();
}

using G = V<P>;
R area(const G& g) {
  if (g.size() < 3) return 0;
  R res = 0;
  P a = g.back();
  for (P b : g) {
    res += crs(a, b) / 2;
    a = b;
  }
  return res;
}
// -1: in, 0: on, 1: out
int contains(const G& g, P p) {
  assert(g.size() >= 3);
  int c = 0;
  P q = p + P(pi, 1), a = g.back();
  for (P b : g) {
    if (!ccw(a, b, p)) return 0;
    if (!sgn(distLS({p, q}, {a, b}))) {
      c += ccw(p, q, intxn({p, q}, {a, b})) >= 0;
    }
    a = b;
  }
  return c & 1 ? -1 : 1;
}
G half_convex_hull(const V<P>& ps, bool strict) {
  G g;
  for (P p : ps) {
    while (g.size() >= 2) {
      int c = ccw(g[g.size() - 2], g.back(), p);
      if (c == 1 or !strict and c == 2) break;
      g.pop_back();
    }
    g.push_back(p);
  }
  g.pop_back();
  return g;
}
G convex_hull(V<P> ps, bool strict = true) {
  sort(begin(ps), end(ps), cmp);
  ps.erase(unique(begin(ps), end(ps), eql), end(ps));
  if (ps.size() < 3) return ps;
  G g = half_convex_hull(ps, strict);
  reverse(begin(ps), end(ps));
  G h = half_convex_hull(ps, strict);
  g.insert(end(g), begin(h), end(h));
  return g;
}
R diameter(const G& g) {
  auto e = minmax_element(begin(g), end(g), cmp);
  int n = g.size(), i = e.first - begin(g), j = e.second - begin(g);
  R res = 0;
  for (int _ = 0; _ < n; ++_) { // n: 半周, 2n: 一周
    res = max(res, distPP(g[i], g[j]));
    int ni = (i + 1) % n, nj = (j + 1) % n;
    if (sgn(crs(g[ni] - g[i], g[nj] - g[j])) < 0) i = ni;
    else j = nj;
  }
  return res;
}

struct C { P o; R r; };
V<P> intxnCL(C c, L l) {
  int s = sgn(distPL(c.o, l), c.r);
  if (s > 0) return {};
  P p = proj(c.o, l);
  if (!s) return {p};
  P q = sqrt(c.r * c.r - norm(p - c.o)) * l.vec() / l.abs();
  return {p - q, p + q};
}
V<P> intxnCC(C c, C d) {
  R a = distPP(c.o, d.o);
  if (!sgn(a)) {
    assert(sgn(c.r, d.r));
    return {};
  }
  P p = polar(c.r / a, acos((a * a + c.r * c.r - d.r * d.r) / (2 * a * c.r)));
  return {c.o + conj(p) * (d.o - c.o), c.o + p * (d.o - c.o)};
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  while (true) {
    int n; cin >> n;
    if (!n) break;
    V<C> cs(n);
    for (C& c : cs) cin >> c.o >> c.r;
    int m; cin >> m;
    while (m--) {
      L s; cin >> s.s >> s.t;
      bool ok = true;
      for (C c : cs) {
        for (P p : intxnCL(c, s)) {
          if (!ccw(s, p)) ok = false;
        }
      }
      cout << (ok ? "Danger" : "Safe") << '\n';
    }
  }
}
