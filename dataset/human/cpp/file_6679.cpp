#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef long double ld;

const ld eps = 1e-9;

struct Point { // ポイントクラス兼ベクトルクラス
    ld x, y;
    Point() {}
    Point(ld x, ld y) : x(x), y(y) {}
    Point operator+(const Point &o) const {
        return Point(x + o.x, y + o.y);
    }
    Point operator-(const Point &o) const {
        return Point(x - o.x, y - o.y);
    }
    Point operator*(ld a) const {
        return Point(a*x, a*y);
    }
    Point operator/(ld a) const {
        return Point(x/a, y/a);
    }
    ld norm() const {
        return sqrt(x*x + y*y);
    }
    Point unit() const { // 単位ベクトル
        return (*this)/norm();
    }
};
ld dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}
ld cross(const Point &a, const Point &b) {
   return a.x * b.y - a.y * b.x;
}
#define CCW 1
#define CW -1
#define CAB 2
#define ABC -2
#define ACB 0
int ccw(Point a, Point b, Point c) {
    // aを基準とする位置ベクトルを考える
	b = b - a; c = c - a;
	if (cross(b, c) > eps) return CCW; // 反時計周り
	if (cross(b, c) < -eps) return CW;// 時計周り
	if (dot(b, c) < 0) return CAB;     // c--a--bがこの順番に一直線上
	if (b.norm() < c.norm()) return ABC; // a--b--cがこの順番に一直線上
	return ACB;                         // a--c--bが一直線上
}
typedef Point Vector;

struct Segment {
    Point from, to;
    Segment() {}
    Segment(Point from, Point to) : from(from), to(to) {}
    ld length() const {
        return (to-from).norm();
    }
    bool contains(const Point &p) const {
        return ccw(from, to, p) == ACB;
    }
};

struct Line : public Segment {
    Line() {}
    Line(Segment s) : Segment(s) {}
    Line(Point from, Point to) : Segment(from, to) {}
    ld distance(const Point &p) const {
        Vector v1 = p - from;
        Vector v2 = to - from;
        ld S = abs(cross(v1, v2));   // v1,v2が張る平行四辺形の面積
        return S / length();         // それを線分の長さで割る
    }
    Point projection(const Point &p) const {
        Vector v1 = p - from, v2 = to - from;
        ld l = dot(v1, v2) / v2.norm();
        return from + (v2.unit()) * l;
    }
};

struct Circle {
    Point o;
    ld r;
    Circle() {}
    Circle(Point o, ld r) : o(o), r(r) {}
    Circle(ld x, ld y, ld r) : o(Point(x, y)), r(r) {}
    bool intersects(const Circle& c) const {
        ld dx = o.x - c.o.x;
        ld dy = o.y - c.o.y;
        return (r + c.r) * (r + c.r) + eps >= dx*dx + dy*dy;
    }
    bool intersects(const Segment& s) const {
        if (contains(s.from) && contains(s.to)) return false;
        Line l(s);
        if (l.distance(o) > r + eps) return false;
        if (contains(s.from) != contains(s.to)) return true;
        return s.contains(l.projection(o));
    }
    bool contains(const Point& p) const {
        ld dx = o.x - p.x;
        ld dy = o.y - p.y;
        return r*r + eps >= dx*dx + dy*dy;
    }
};

int main() {
    int n, m;
    while (cin >> n, n) {
        vector<Circle> walls(n);
        for (int i = 0; i < n; i++) {
            ld x, y, r; cin >> x >> y >> r;
            walls[i] = Circle(x, y, r);
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            Point t, s;
            cin >> t.x >> t.y >> s.x >> s.y;
            Segment eye(t, s);
            bool safe = false;
            for (int j = 0; j < n; j++) {
                if (walls[j].intersects(eye)) {
                    safe = true;
                    break;
                }
            }
            cout << (safe ? "Safe" : "Danger") << endl;
        }
    }
    return 0;
}
