#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <iomanip>
#include <cmath>


using namespace std;


typedef long long ll;
typedef long double ld;


const ll MOD_CONST = 1000000007ll;


ll modSum(ll a, ll b, ll MOD = MOD_CONST) {
  return ((a % MOD) + (b % MOD)) % MOD;
}


ll modSubtract(ll a, ll b, ll MOD = MOD_CONST) {
  return (((a % MOD) - (b % MOD)) + MOD + MOD) % MOD;
}


ll modProd(ll a, ll b, ll MOD = MOD_CONST) {
  return ((a % MOD) * (b % MOD)) % MOD;
}


ll getPowMod(ll x, ll e, ll MOD = MOD_CONST) {
  if (e == 0) return 1;
  if (e % 2 == 0) {
    ll tmp = getPowMod(x, e/2, MOD);
    return modProd(tmp, tmp);
  } else {
    ll tmp = getPowMod(x, e-1, MOD);
    return modProd(tmp, x);
  }
}


ll getPow(ll x, ll e) {
  if (e == 0) return 1;
  if (e % 2 == 0) {
    ll tmp = getPow(x, e/2);
    return tmp * tmp;
  } else {
    ll tmp = getPow(x, e-1);
    return tmp * x;
  }
}


ll getInverse(ll x, ll MOD = MOD_CONST) {
  return getPowMod(x, MOD-2, MOD);
}


bool isEven(ll x) {
  ll tmp = ((x % 2) + 2) % 2;
  return tmp == 0;
}


ll getSumOfDigitsInBase(ll n, ll b) {
  ll ret = 0;
  while (n > 0) {
    ret += n % b;
    n /= b;
  }
  return ret;
}


vector<int> getKMP(string &s) {
  int len = (int)s.size();
  vector<int> ret (len, 0);
  for (int i = 1 ; i < len ; i++) {
    int at = ret[i-1];
    while (at > 0 && s[i] != s[at]) {
      at = ret[at-1];
    }
    if (s[i] == s[at]) {
      at++;
    }
    ret[i] = at;
  }
  return ret;
}


string getSubstring(string &s, int from, int to) {
  int l = to-from+1;
  if (l <= 0) {
    return "";
  }
  return s.substr(from, l);
}

ll gcd(ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}


pair<ll, ll> getIntersectingRange(ll a1, ll b1, ll a2, ll b2) {
  ll s = max(a1, a2);
  ll e = min(b1, b2);

  return {s, e};
}


bool isNonEmptyIntersection(ll a1, ll b1, ll a2, ll b2) {
  auto p = getIntersectingRange(a1, b1, a2, b2);
  return p.first <= p.second;
}


double getPointDistance(double x1, double y1, double x2, double y2) {
  double dx = x1-x2;
  double dy = y1-y2;
  double d = (dx * dx) + (dy * dy);
  return sqrt(d);
}


















const int MAXN = 1003;
const double INF = 1e32;


int N;
bool visit[MAXN];
int x[MAXN], y[MAXN], r[MAXN];
double dist[MAXN];
double G[MAXN][MAXN];


double getDist(int i, int j) {
  return max(0.0, getPointDistance(x[i], y[i], x[j], y[j]) - r[i] - r[j]);
}


void input() {
  int xs, ys, xt, yt;
  cin >> xs >> ys >> xt >> yt;
  cin >> N;
  for (int i = 1 ; i <= N ; i++) {
    cin >> x[i] >> y[i] >> r[i];
  }
  x[N+1] = xs;
  y[N+1] = ys;
  r[N+1] = 0;
  x[N+2] = xt;
  y[N+2] = yt;
  r[N+2] = 0;
}


void preprocess() {
  for (int i = 1 ; i <= N+2 ; i++) {
    for (int j = 1 ; j < i ; j++) {
      G[i][j] = G[j][i] = getDist(i, j);
    }
  }
}


void solve() {
  for (int i = 1 ; i <= N+2 ; i++) {
    dist[i] = INF;
  }
  dist[N+1] = 0;
  while (true) {
    int minId = -1;
    for (int i = 1 ; i <= N+2 ; i++) {
      if ((!visit[i]) && (minId == -1 || dist[minId] > dist[i])) {
        minId = i;
      }
    }
    if (minId == -1 || dist[minId] == INF) break;
    visit[minId] = true;
    for (int i = 1 ; i <= N+2 ; i++) {
      dist[i] = min(dist[i], dist[minId]+G[minId][i]);
    }
  }
  cout << fixed << setprecision(12) << dist[N+2];
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);

  int T;
//  cin >> T;
  T = 1;

  for (int i = 0 ; i < T ; i++) {
    input();
    preprocess();
    solve();
  }

  return 0;
}
