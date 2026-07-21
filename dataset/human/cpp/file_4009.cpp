#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

struct crl {
  ll x, y, r;
};

ll sqr(ll x) {
  return x * x;
}

bool intersect(const crl &a, const crl &b) {
  ll dx = a.x - b.x;
  ll dy = a.y - b.y;
  return sqr(a.r + b.r) >= sqr(dx) + sqr(dy) || sqr(dx) + sqr(dy) <= sqr(a.r - b.r);
}

crl readCrl() {
  crl c;
  cin >> c.x >> c.y >> c.r;
  return c;
}

crl readCrl(ll r) {
  crl c;
  cin >> c.x >> c.y;
  c.r = r;
  return c;
}

ld dist(const crl &a, const crl &b) {
  return hypot(a.x - b.x, a.y - b.y) - a.r - b.r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<crl> a(1002);
  a[0] = readCrl(0);
  a.back() = readCrl(0);
  ll n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    a[i] = readCrl();
  }
  a[n + 1] = a.back();
  a.resize(n + 2);
  n += 2;
  const ll INF = 1'000'000'000'000'000'000LL;
  vector<ld> d(n, INF);
  vector<char> used(n);
  vector<vector<ld>> g(n, vector<ld>(n, INF));
  for (int i = 0; i < n; i++) {
    g[i][i] = 0;
    for (int j = i + 1; j < n; j++) {
      if (!intersect(a[i], a[j])) {
        g[i][j] = g[j][i] = dist(a[i], a[j]);
      } else {
        g[i][j] = g[j][i] = 0;
      }
    }
  }
  d[0] = 0;
  for (int i = 0; i < n; i++) {
    int v = -1;
    for (int j = 0; j < n; j++) {
      if (!used[j] && (v == -1 || d[v] > d[j])) {
        v = j;
      }
    }
    used[v] = true;
    for (int j = 0; j < n; j++) {
      d[j] = min(d[j], d[v] + g[v][j]);
    }
  }
  cout.precision(20);
  cout << fixed << d.back();
  return 0;
}
