#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <math.h>
#include <tuple>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define REPR(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define FOR(i, n, m) for (ll i = (n); i < (m); ++i)
#define FORR(i, n, m) for (ll i = (m) - 1; i >= (n); --i) 
#define FORE(x, xs) for (auto &x: (xs))
#define ALL(v) v.begin(), v.end()
#define ZERO(a) memset(a,0,sizeof(a))
#define P(x, y) make_pair(x, y)

const int INF = 1000000009;
const double INF_D = INF+0.1;
const int MOD = 1000000007;
const double EPS = 1e-14;
const double PI = acos(-1);


const int MAX = 1e5+2; /// 最大頂点数

ll N, M; /// N:頂点数、M:辺の数

vector<pair<int, ld> > G[MAX]; /// G[i]は頂点iから出る辺、<行き先、距離>
ld dist[MAX]; /// dist[j]は注目する頂点kからの最短距離、特にdist[k]=0

struct Circle {
  int x, y, r;

  ld dist(Circle& other) {
    return max(
        0.0, 
        pow(pow(x-other.x, 2) + pow(y-other.y, 2), 0.5) - (r+other.r)
    );
  }
};

Circle circles[MAX];

void dijkstra(int s) { /// sは始点
  fill_n(dist, N+2, INF_D);
  priority_queue<pair<ld, int> > q;
  q.push(make_pair(0.0, s)); /// queueは距離、始点の順で使う。大きい方が優先されるので、距離は負の値で扱う
  while (!q.empty()) {
    int t;
    ld d; /// t:終点、d:始点からtまでの距離
    tie(d, t) = q.top(); q.pop();
    if (dist[t] != INF_D) continue;
    dist[t] = -d;
    FORE (e, G[t]) {
      q.push(make_pair(d-e.second, e.first));
    }
  }
}

int main() {

  Circle s, t;
  cin >> s.x >> s.y >> t.x >> t.y;
  s.r = 0, t.r = 0;

  cin >> N;
  circles[0] = s; circles[N+1] = t;

  REP (i, N) {
    Circle c;
    cin >> c.x >> c.y >> c.r;
    circles[i+1] = c;
  }

  REP (j, N+2) REP (i, j) {
    ld d = circles[i].dist(circles[j]);
    G[i].push_back(make_pair(j, d));
    G[j].push_back(make_pair(i, d));
  }

  dijkstra(0);

  cout << fixed;
  cout << setprecision(10) << dist[N+1] << endl;

  return 0;
}
