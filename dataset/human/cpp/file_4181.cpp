#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>
#include <complex>

using namespace std;
typedef long long li;
typedef pair <li, li> pi;
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
typedef complex<double> pt;

struct ShortestPath {
    struct edge { int to; double cost; };
    int v;
    vector<vector<edge> > g;
    ShortestPath(int _v): v(_v), g(v) {}
    void add_edge (int from, int to, double cost) {
        g[from].push_back((edge){to, cost});
    }
    vector<double> shortest_path(int init) {
        vector<double> min_cost(v, 1e100);
        priority_queue<pair<double, int> > q;
        min_cost[init] = 0;
        q.push(make_pair(0, init));
        while (not q.empty()) {
            double cost = -q.top().first;
            int pos = q.top().second;
            q.pop();

            for (int i = 0; i < g[pos].size(); ++i) {
                int npos = g[pos][i].to;
                double ncost = cost + g[pos][i].cost;
                if (ncost < min_cost[npos]) {
                    min_cost[npos] = ncost;
                    q.push(make_pair(-ncost, npos));
                }
            }
        }
        return min_cost;
    }

    double shortest_path(int s, int t) {
        return shortest_path(s)[t];
    }
};

pt read() {
    double x, y;
    cin >> x >> y;
    return pt(x, y);
}

int main() {
    const pt start = read();
    const pt goal = read();

    int n;
    cin >> n;

    vector<pt> c(n);
    vector<double> r(n);

    rep(i, n) {
        c[i] = read();
        cin >> r[i];
    }

    c.push_back(start);
    r.push_back(0);
    c.push_back(goal);
    r.push_back(0);

    n += 2;
    ShortestPath sp(n);

    rep(i, n) {
        rep(j, i) {
            double cost = max(0., abs(c[i] - c[j]) - r[i] - r[j]);
            sp.add_edge(i, j, cost);
            sp.add_edge(j, i, cost);
        }
    }

    cout.precision(12);
    cout << sp.shortest_path(n - 2, n - 1) << endl;


    return 0;
}
