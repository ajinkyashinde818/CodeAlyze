#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <climits>
#include <ctime>
#include <cassert>
using namespace std;

#define rep(i,a,n) for(int i=a; i<n; i++)
#define repq(i,a,n) for(int i=a; i<=n; i++)
#define repr(i,a,n) for(int i=a; i>=n; i--)
#define pb(a) push_back(a)
#define fr first
#define sc second
#define INF 2000000000
#define int long long int

#define X real()
#define Y imag()
#define EPS (1e-10)
#define EQ(a,b) (abs((a) - (b)) < EPS)
#define EQV(a,b) ( EQ((a).X, (b).X) && EQ((a).Y, (b).Y) )
#define LE(n, m) ((n) < (m) + EPS)
#define LEQ(n, m) ((n) <= (m) + EPS)
#define GE(n, m) ((n) + EPS > (m))
#define GEQ(n, m) ((n) + EPS >= (m))

typedef vector<int> VI;
typedef vector<VI> MAT;
typedef pair<int, int> pii;
typedef long long ll;

typedef complex<double> P;
typedef pair<P, P> L;
typedef pair<P, double> C;

int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
int const MOD = 1000000007;

namespace std {
    bool operator<(const P& a, const P& b) {
        return a.X != b.X ? a.X < b.X : a.Y < b.Y;
    }
}

// 移動元と行先と辺のコストを記録する構造体
struct Edge {
    int from, to;
    long double cost;
    Edge(int s, long double d) : to(s), cost(d) {}
    Edge(int f, int s, long double d) : from(f), to(s), cost(d) {}

    bool operator<(const Edge &e) const {
        return cost < e.cost;
    }
    bool operator>(const Edge &e) const {
        return cost > e.cost;
    }
};

// 1つの頂点について、辺の情報を保存するために必要な vector
// Edgesのサイズは各頂点から出る辺の数に等しくなる
typedef vector<Edge> Edges;

// 辺の情報を保存する vector
// Graphのサイズは頂点の数に等しいので、 V である。
typedef vector<Edges> Graph;
typedef pair<long double, int> PDI;

vector<long double> dijkstra(Graph &G, int s) {
    int V = G.size();
    vector<long double> d(V); fill(d.begin(), d.end(), LLONG_MAX);
    priority_queue<PDI, vector<PDI>, greater<PDI> > que;
    d[s] = 0;
    que.push(PDI(0,s));

    while(!que.empty()) {
        PDI p = que.top(); que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int i=0; i<G[v].size(); i++) {
            Edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(PDI(d[e.to], e.to));
            }
        }
    }
    return d;
}

signed main() {
    int xs, ys, xt, yt; cin >> xs >> ys >> xt >> yt;
    int n; cin >> n;
    int x[1010], y[1010], r[1010];
    Graph G(n+2);
    rep(i,0,n) cin >> x[i] >> y[i] >> r[i];
    x[n] = xs, y[n] = ys, r[n] = 0;
    x[n+1] = xt, y[n+1] = yt, r[n+1] = 0;

    rep(i,0,n+2) rep(j,0,n+2) {
        if(i == j) continue;
        int xx = (x[i] - x[j]) * (x[i] - x[j]);
        int yy = (y[i] - y[j]) * (y[i] - y[j]);
        long double dist = max((long double)0.0, sqrt(xx + yy) - (long double)r[i] - (long double)r[j]);
        G[i].pb(Edge(j, dist));
    }
    vector<long double> ans = dijkstra(G, n);
    cout << fixed << setprecision(15) << ans[n+1] << endl;
    return 0;
}
