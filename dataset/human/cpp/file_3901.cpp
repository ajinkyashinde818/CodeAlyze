#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <cassert>
#include <random>
#include <tuple>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<double, int> PDI;

struct Edge{
    int to; double cost;
    Edge(int t, double c): to(t), cost(c) { }
};
using Graph = vector<vector<Edge>>;

struct Point{
    int x; int y; int r;
    Point(int x, int y, int r): x(x), y(y), r(r) { }
};


double getDist(int x1, int y1, int r1, int x2, int y2, int r2) {
    double dist = sqrt(ll(x2 - x1) * ll(x2 - x1) + ll(y2 - y1) * ll(y2 - y1));
    if (r1 + r2 >= dist) return 0;
    else return dist - (r1 + r2);
}

int n;
vector<double> dijkstra(int s, Graph& g) {
    vector<double> dist(n+2, 1e18);
    dist[s] = 0;
    priority_queue<PDI, vector<PDI>, greater<PDI>> pq;
    pq.push(PDI(0, s));
    while (!pq.empty()) {
        PDI q = pq.top(); pq.pop();
        double d = q.first;
        int v = q.second;
        if (dist[v] + 1e-9 < d) continue;
        for (auto ne: g[v]) {
            double nd = ne.cost;
            int nv = ne.to;
            if (dist[v] + nd < dist[nv]) {
                dist[nv] = dist[v] + nd;
                pq.push(PDI(dist[nv], nv));
            }
        }
    }
    return dist;
}

int main() {
    int xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;
    cin >> n;

    Graph g(n+2);
    vector<Point> p;


    rep(i, n) {
        int x, y, r;
        cin >> x >> y >> r;
        p.push_back(Point(x, y, r));
    }

    p.push_back(Point(xs, ys, 0));
    p.push_back(Point(xt, yt, 0));

    rep(i, n+2) {
        for (int j = i+1; j < n+2; j++) {
            g[i].push_back(Edge(j, getDist(p[i].x, p[i].y, p[i].r, p[j].x, p[j].y, p[j].r)));
            g[j].push_back(Edge(i, getDist(p[i].x, p[i].y, p[i].r, p[j].x, p[j].y, p[j].r)));
        }
    }

    vector<double> d = dijkstra(n, g);

    cout << fixed;
    cout << setprecision(10) << d[n+1] << endl;
}
