#include <bits/stdc++.h>
using i64 = long long;

const double pi = std::acos(-1);

int sgn(double a) { return a < -1e-8 ? -1 : a > 1e-8 ? 1 : 0; }

struct Point {
    double x, y;

    Point(double x, double y) : x(x), y(y) {}

    double abs() { return std::hypot(x, y); }
    double arg() { return std::atan2(y, x); }
    
    double dot(const Point &p) { return x * p.x + y * p.y; }
    double det(const Point &p) { return x * p.y - y * p.x; }
};

Point operator+(const Point &lhs, const Point &rhs) {
    return { lhs.x + rhs.x, lhs.y + rhs.y };
}

Point operator-(const Point &lhs, const Point &rhs) {
    return { lhs.x - rhs.x, lhs.y - rhs.y };
}

Point operator-(const Point &p) {
    return { -p.x, -p.y };
}

Point operator*(const Point &lhs, const Point &rhs) {
    return { lhs.x * rhs.x - lhs.y * rhs.y, lhs.x * rhs.y + lhs.y * rhs.x };
}

Point operator*(const Point &lhs, double k) {
    return { lhs.x * k, lhs.y * k };
}

Point operator/(const Point &lhs, double k) {
    return { lhs.x / k, lhs.y / k };
}

bool operator<(const Point &lhs, const Point &rhs) {
    auto s = sgn(lhs.y - rhs.y);
    return s ? s < 0 : sgn(lhs.x - rhs.x) < 0;
}

int iSP(const Point &a, const Point &b, const Point &c) {
    auto sd = sgn((b - a).det(c - a));
    return sd ? sd
        : sgn((b - a).dot(c - a)) < 0 ? -2
        : sgn((a - b).dot(c - b)) < 0 ? 2
        : 0;
}

struct Segment {
    Point a, b;
    Segment(Point a, Point b) : a(a), b(b) {}
};

double dist(const Segment &l, const Point &p) {
    if ((l.b - l.a).dot(p - l.a) < 0) {
        return (p - l.a).abs();
    } else if ((l.a - l.b).dot(p - l.b) < 0) {
        return (p - l.b).abs();
    } else {
        return abs((p - l.a).det(l.b - l.a) / (l.b - l.a).abs());
    }
}

struct Circle {
    Point c;
    double r;

    Circle(Point c, double r) : c(c), r(r) {}
    Circle(double x, double y, double r) : c(x, y), r(r) {}
};

int main() {
    double sx, sy, tx, ty;
    int n;
    std::cin >> sx >> sy >> tx >> ty >> n;
    std::vector<std::vector<std::pair<int, double>>> g(n + 2);
    std::vector<Circle> cs { { sx, sy, 0 }, { tx, ty, 0 } };
    auto dst = (cs[0].c - cs[1].c).abs();
    g[0].emplace_back(1, dst);
    g[1].emplace_back(0, dst);
    for (int i = 2; i < n + 2; i++) {
        double x, y, r;
        std::cin >> x >> y >> r;
        cs.emplace_back(x, y, r);
        for (int j = 0; j < i; j++) {
            auto d = std::max((cs[j].c - cs.back().c).abs() - cs[j].r - cs.back().r, 0.0);
            g[i].emplace_back(j, d);
            g[j].emplace_back(i, d);
        }
    }

    using P = std::pair<double, int>;
    std::priority_queue<P, std::vector<P>, std::greater<>> q;
    std::vector<double> dist(g.size(), std::numeric_limits<double>::max());
    dist[0] = 0;
    q.emplace(0, 0);
    while (!q.empty()) {
        auto v = q.top();
        q.pop();
        if (sgn(dist[v.second] - v.first) < 0) continue;
        for (auto &e : g[v.second]) {
            auto c = v.first + e.second;
            if (sgn(dist[e.first] - c) <= 0) continue;
            dist[e.first] = c;
            q.emplace(dist[e.first], e.first);
        }
    }

    std::cout << std::setprecision(10) << dist[1] << std::endl;

    return 0;
}
