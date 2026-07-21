#include <algorithm>
#include <cmath>
#include <complex>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <functional>
#include <cstring>
#include <regex>
#include <random>
#include <cassert>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, s, n) for (int i = (s); i < (int)(n); i++)
#define revrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define revrepr(i, s, n) for (int i = (n) - 1; i >= s; i--)
#define debug(x) cerr << #x << ": " << x << "\n"

using ll = long long;
using P = pair<int, int>;

const long long MOD = 1e9+7;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<class T>
istream& operator >>(istream &is, vector<T> &v) {
    for (int i = 0; i < (int)v.size(); i++) cin >> v.at(i);
    return is;
}

template<class T, class U>
ostream& operator <<(ostream &os, pair<T, U> p) {
    cout << '(' << p.first << ", " << p.second << ')';
    return os;
}

template<class T>
void print(const vector<T> &v, const string &delimiter) { rep(i, v.size()) cout << (0 < i ? delimiter : "") << v.at(i); cout << endl; }

template<class T>
void print(const vector<vector<T>> &vv, const string &delimiter) { for (const auto &v: vv) print(v, delimiter); }

struct Point {
    double x, y;
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
};
inline Point operator +(const Point &p, const Point &q) { return Point(p.x + q.x, p.y + q.y); }
inline Point operator -(const Point &p, const Point &q) { return Point(p.x - q.x, p.y - q.y); }
inline double dot(const Point &p, const Point &q) { return p.x * q.x + p.y * q.y; }
inline double abs(const Point &p) { return sqrt(dot(p, p)); }

struct Circle {
    Point p;
    double r;
    Circle(Point p = Point(0.0, 0.0), double r = 0.0) : p(p), r(r) {}
};

inline double distance(const Circle &c, const Circle &d) { return max(0.0, abs(c.p - d.p) - c.r - d.r); }

using PDI = pair<double, int>;

struct Edge {
    int to;
    double cost;
};

const long long INF = 1ll << 60;
const int MAX_V = 2000;
vector<vector<Edge>> G(MAX_V + 1);
vector<double> d(MAX_V + 1, INF);

void dijkstra(int s) {
    priority_queue<PDI, vector<PDI>, greater<PDI>> que;
    d[s] = 0;
    que.push(PDI(0, s));

    while (!que.empty()) {
        PDI p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i = 0; i < (int)G[v].size(); i++) {
            Edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(PDI(d[e.to], e.to));
            }
        }
    }
}

int main() {
    double xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    int n;
    cin >> n;
    vector<Circle> cs(n + 2);
    rep(i, n) {
        double x, y, r;
        cin >> x >> y >> r;
        cs[i + 1] = Circle(Point(x, y), r);
    }
    cs[0] = Circle(Point(xa, ya));
    cs[n + 1] = Circle(Point(xb, yb));
    
    rep(i, n + 2) repr(j, i + 1, n + 2) {
        double d = distance(cs[i], cs[j]);
        G[i].push_back(Edge{j, d});
        G[j].push_back(Edge{i, d});
    }
    
    dijkstra(0);
    printf("%.15lf\n", d[n + 1]);
}
