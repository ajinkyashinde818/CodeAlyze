#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>

using namespace std;

template<typename T, typename S>
istream& operator >> (istream& is, pair<T, S>& p) {
    is >> p.first >> p.second;
    return is;
}

template<typename T>
istream& operator >> (istream& is, vector<T>& v) {
    for (auto& x : v) {
        is >> x;
    }
    return is;
}

template<typename T>
ostream& operator << (ostream& os, const vector<T>& v) {
    for (auto& x : v) {
        os << x << " ";
    }
    os << "\n";
    return os;
}

using ld = long double;

struct Point {
    ld x, y;

    Point () {}

    Point(ld x, ld y): x(x), y(y) {}

    Point operator + (const Point& other) const {
        return {x + other.x, y + other.y};
    }

    Point operator - () const {
        return {-x, -y};
    }

    Point operator - (const Point& other) const {
        return *this + (- other);
    }

    ld operator * (const Point& other) const {
        return x * other.x + y * other.y;
    }

    ld len () const {
        return sqrt(*this * *this);
    }
};

struct Edge {
    int s, t;
    ld c;
};

const ld INF = 1e12;
using pldi = pair<ld, int>;

vector<ld> dijkstra(int v, const vector<vector<Edge>>& e) {
    vector<ld> dist(e.size(), INF);
    dist[v] = 0;

    set<pldi> grey;
    grey.insert({0.0, v});
    while (!grey.empty()) {
        auto [du, u] = *grey.begin();
        grey.erase(grey.begin());
        for (auto edge : e[u]) {
            int t = edge.t;
            ld c = edge.c;
            if (dist[t] > du + c) {
                grey.erase({dist[t], t});
                dist[t] = du + c;
                grey.insert({dist[t], t});
            }
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Point S, T;
    cin >> S.x >> S.y >> T.x >> T.y;
    int n;
    cin >> n;
    vector<Point> ps(n);
    vector<ld> rs(n);
    for (int i = 0; i < n; ++i) {
        cin >> ps[i].x >> ps[i].y >> rs[i];
    }
    vector<vector<Edge>> e(n + 2);
    {
            int u = n + 1;
            int v = n;
            ld d = max((ld)0.0, (T - S).len());
            e[u].push_back({u, v, d});
            e[v].push_back({v, u, d});
    }
    for (int i = 0; i < n; ++i) {
        {
            int u = i;
            int v = n;
            ld d = max((ld)0.0, (ps[i] - S).len() - rs[i]);
            e[u].push_back({u, v, d});
            e[v].push_back({v, u, d});
        }
        {
            int u = i;
            int v = n + 1;
            ld d = max((ld)0.0, (ps[i] - T).len() - rs[i]);
            e[u].push_back({u, v, d});
            e[v].push_back({v, u, d});
        }
        for (int j = i + 1; j < n; ++j) {
            ld d = max((ld)0.0, (ps[i] - ps[j]).len() - rs[i] - rs[j]);
            e[i].push_back({i, j, d});
            e[j].push_back({j, i, d});
        }
    }
    auto dist = dijkstra(n, e);
    cout << setprecision(10) << fixed << dist[n + 1];

}
