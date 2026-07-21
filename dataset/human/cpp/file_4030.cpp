#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
// using WGraph = vector<vector<pair<int, ll>>>;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;
constexpr long long LINF = 1e18;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;

using WGraph = vector<vector<pair<int, double>>>;

class Point {
    public:
        double x, y;
        Point(double xx = 0.0, double yy = 0.0) : x(xx), y(yy) {}
        Point(const Point &p) : x(p.x), y(p.y) {}
        Point& operator=(const Point &p) { if (this != &p) { x = p.x; y = p.y; } return *this; }
        Point operator+() const { return Point(x, y); }
        Point operator-() const { return Point(-x, -y); }
        Point operator+(const Point &p) const { return Point(*this) += p; }
        Point operator-(const Point &p) const { return Point(*this) -= p; }
        Point operator*(double v) const { return Point(*this) *= v; }
        Point operator/(double v) const { return Point(*this) /= v; }
        Point& operator+=(const Point &p) { x += p.x; y += p.y; return *this; }
        Point& operator-=(const Point &p) { x -= p.x; y -= p.y; return *this; }
        Point& operator*=(double v) { x *= v; y *= v; return *this; }
        Point& operator/=(double v) { x /= v; y /= v; return *this; }
        friend Point operator*(double v, const Point &p) { return p * v; }
        friend Point rot(const Point &p, double angle) { return Point(std::cos(angle) * p.x - std::sin(angle) * p.y, std::sin(angle) * p.x + std::cos(angle) * p.y); }
        friend Point rot90(const Point &p) { return Point(-p.y, p.x); }
        friend double dot(const Point &p, const Point &q) { return p.x * q.x + p.y * q.y; }
        friend double cross(const Point &p, const Point &q) { return p.x * q.y - p.y * q.x; }
        friend double abs(const Point &p) { return sqrt(dot(p, p)); }
        friend double dis(const Point &p, const Point &q) { return abs(p - q); }
        friend bool eq(const Point &p, const Point &q) { return dis(p, q) < EPS; }
        friend std::istream& operator>>(std::istream &s, Point &p) { return s >> p.x >> p.y; }
        friend std::ostream& operator<<(std::ostream &s, const Point &p) { return s << "(" << p.x << ", " << p.y << ")"; }
};

double dijkstra(const WGraph &G, const int s, const int t) {
    int n = (int)G.size();
    std::vector<double> dis(n, LINF);
    dis.at(s) = 0;
    using P = std::pair<double, int>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> que;
    que.push(std::make_pair(0, s));

    while (!que.empty()) {
        auto p = que.top();
        que.pop();
        int v = p.second;
        if (dis.at(v) < p.first) {
            continue;
        }
        for (auto e : G.at(v)) {
            if (dis.at(e.first) > dis.at(v) + e.second) {
                dis.at(e.first) = dis.at(v) + e.second;
                que.push(std::make_pair(dis.at(e.first), e.first));
            }
        }
    }
    return dis.at(t);
}

void solve() {
    Point s, t;
    cin >> s >> t;
    int n;
    cin >> n;
    vector<Point> barrirs(n);
    vector<double> r(n);
    for (int i=0; i<n; ++i) {
        cin >> barrirs.at(i) >> r.at(i);
    }

    WGraph G(n+2);
    for (int i=0; i<n; ++i) {
        G.at(0).push_back({i+1, max(0.0, dis(s, barrirs.at(i)) - r.at(i))});
    }
    for (int i=0; i<n; ++i) {
        for (int j=i+1; j<n; ++j) {
            double tmp = max(0.0, dis(barrirs.at(i), barrirs.at(j)) - r.at(i) - r.at(j));
            G.at(i+1).push_back({j+1, tmp});
            G.at(j+1).push_back({i+1, tmp});
        }
    }
    for (int i=0; i<n; ++i) {
        G.at(i+1).push_back({n+1, max(0.0, dis(t, barrirs.at(i)) - r.at(i))});
    }
    G.at(0).push_back({n+1, dis(s, t)});

    cout << dijkstra(G, 0, n+1) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
