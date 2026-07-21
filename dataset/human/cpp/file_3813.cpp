#include<bits/stdc++.h>
using namespace std;
struct _IO{_IO(){ios::sync_with_stdio(0);cin.tie(0);}}_io;

typedef long long ll;
typedef long double db;
typedef unsigned long long ull;
typedef vector<int> vi; typedef vector<vi> vii;
typedef pair<int, int> pi;
typedef tuple<int, int, int> t3;
typedef map<int, int> mi;
#define fi first
#define se second
#define be begin()
#define ed end()
#define sz size()
#define cl clear()
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define lb(v, x) lower_bound(v.begin(), v.end(), x)
#define lbi(v, x) (lb(v, x) - v.begin())
#define tp(t, x, y) t x, y; tie(x, y)
#define tp3(t, x, y, z) t x, y, z; tie(x, y, z)
#define mp make_pair
#define mt make_tuple
#define co const
#define fc(x) for(int x = 1, _end = ri(); x <= _end; x++)
void uni(vi &v) { sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end()); }

db rd() { db x; cin >> x; return x; }
ll ri() { ll x; cin >> x; return x; }
string rs() { string s; cin >> s; return s; }
pi rpi() { pi x; cin >> x.fi >> x.se; return x; }
vi rvi(int n, int f = 0) { vi v(n + f); for (int i = f; i < v.size(); i++) cin >> v[i]; return v; }
vii rvii(int n, int m, int f = 0) { vii v(n + f, vi(n + f)); for (int i = f; i < v.size(); i++) for (int j = f; j < v[0].size(); j++) cin >> v[i][j]; return v; }
void pr() {}; template <class T, class ...U> void pr(T x, U ...y) { cout << x << ' ', pr(y...); }
void prl() { cout << '\n'; }; template <class T, class ...U> void prl(T x, U ...y) { cout << x << ' ', prl(y...); }
void pr(const vi &v, int f = 0) { for (int i = f; i < v.size(); i++) cout << v[i] << ' '; }
void prl(const vi &v, int f = 0) { pr(v, f); cout << '\n'; }
void pr(const pi &x) { cout << x.fi << ' ' << x.se; };
void prl(const pi &x) { pr(x); cout << '\n'; }

#define rep(i, l, r) for (int i = l; i < r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)

const int N = 2e5 + 5, M = 1e9 + 7;

ll sqr(ll x) { return x * x; }

ll dis2(co pi &a, co pi &b) {
  return sqr(a.fi - b.fi) + sqr(a.se - b.se);
}

db dis(co t3 &t, co pi &p) {
  tp3(ll, x, y, r) = t;
  db d = sqrt(dis2(mp(x, y), p));
  return max(d - r, db(0));
}
db dis(co t3 &a, co t3 &b) {
  tp3(ll, x, y, r) = a;
  tp3(ll, u, v, w) = b;
  db d = sqrt(dis2(mp(x, y), mp(u, v)));
  return max(d - r - w, db(0));
}

vector<pair<db, int>> g[N];

int main() {
  cout << setprecision(10) << fixed;
  pi a = rpi(), b = rpi();
  int n = ri();
  vector<t3> vp(n);
  rep(i, 0, n) {
    vp[i] = {ri(), ri(), ri()};
    g[i].eb(dis(vp[i], a), n);
    g[n].eb(dis(vp[i], a), i);
    g[i].eb(dis(vp[i], b), n + 1);
    g[n + 1].eb(dis(vp[i], b), i);
  }
  rep(i, 0, n) {
    rep(j, i + 1, n) {
      g[i].eb(dis(vp[i], vp[j]), j);
      g[j].eb(dis(vp[i], vp[j]), i);
    }
  }
  g[n].eb(sqrt(dis2(a, b)), n+1);
  g[n+1].eb(sqrt(dis2(a, b)), n);
  set<pair<db, int>> s = {{0, n}};
  vector<db> d(n + 2, 1e15);
  d[n] = 0;
  while (s.size()) {
    auto p = *s.begin(); s.erase(s.begin());
    for (auto &e : g[p.se])
      if (p.fi + e.fi < d[e.se])
        s.erase({d[e.se], e.se}),
        d[e.se] = p.fi + e.fi,
        s.insert({d[e.se], e.se});
  }
  pr(d[n+1]);
}
