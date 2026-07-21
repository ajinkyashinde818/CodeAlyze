#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const double PI = acos(-1);
const double EPS = 1e-10;
int sgn(double d) { return d > EPS ? 1 : d < -EPS ? -1 : 0; }
 
struct Point {
  double x, y;
  Point() {}
  Point (const double& x, const double& y) : x(x), y(y) {}
  Point& operator += (const Point& other) { x += other.x; y += other.y; return *this; }
  Point& operator -= (const Point& other) { x -= other.x; y -= other.y; return *this; }
  Point& operator *= (const double& factor) { x *= factor; y *= factor; return *this; }
  Point& operator /= (const double& factor) { x /= factor; y /= factor; return *this; }
};
using Vector = Point;
using Polygon = vector<Point>;
Point operator + (const Point&lhs, const Point& rhs) { return Point(lhs.x + rhs.x, lhs.y + rhs.y); }
Point operator - (const Point& lhs, const Point& rhs) { return Point(lhs.x - rhs.x, lhs.y - rhs.y); }
Point operator * (const Point& lhs, const double& factor) { return Point(lhs.x * factor, lhs.y * factor); }
Point operator * (const double& factor, const Point& rhs) { return Point(factor * rhs.x, factor * rhs.y); }
Point operator / (const Point& lhs, const double& factor) { return Point(lhs.x / factor, lhs.y / factor); }
double operator * (const Point& lhs, const Point& rhs) { return lhs.x * rhs.x + lhs.y * rhs.y; }
double operator ^ (const Point& lhs, const Point& rhs) { return lhs.x * rhs.y - lhs.y * rhs.x; }
bool operator == (const Point& lhs, const Point& rhs) { return sgn(lhs.x - rhs.x) == 0 && sgn(lhs.y - rhs.y) == 0; }
bool operator != (const Point& lhs, const Point& rhs) { return !(lhs == rhs); }
bool operator < (const Point& lhs, const Point& rhs) { return sgn(lhs.x - rhs.x) ? lhs.x < rhs.x : lhs.y < rhs.y; }
bool operator > (const Point& lhs, const Point& rhs) { return rhs < lhs; }
bool operator <= (const Point& lhs, const Point& rhs) { return !(lhs > rhs); }
bool operator >= (const Point& lhs, const Point& rhs) { return !(lhs < rhs); }
istream& operator >> (istream& is, Point& point) { return is >> point.x >> point.y; }
ostream& operator << (ostream& os, Point& point) { return os << "(" << point.x << "," << point.y << ")"; }
double norm(const Point& point) { return point.x * point.x + point.y * point.y; }
double abs(const Point& point) { return sqrt(norm(point)); }
double arg(const Point& point) { return atan2(point.y, point.x); }
Point polar(const double& a, const double& r) { return Point(cos(r) * a, sin(r) * a); }
bool sort_x(Point lhs, Point rhs) { return sgn(lhs.x - rhs.x) ? lhs.x < rhs.x : lhs.y < rhs.y; }
bool sort_y(Point lhs, Point rhs) { return sgn(lhs.y - rhs.y) ? lhs.y < rhs.y : lhs.x < rhs.x; }
 
struct Segment {
  Point p1, p2;
  Segment() {}
  Segment(const Point& p1, const Point& p2) : p1(p1), p2(p2) {}
};
using Line = Segment;
istream& operator >> (istream& is, Segment& segment) { return is >> segment.p1 >> segment.p2; }
ostream& operator << (ostream& os, Segment& segment) { return os << "(" << segment.p1 << "," << segment.p2 << ")"; }
 
struct Circle {
  Point c;
  double r;
  Circle() {}
  Circle(const Point& c, const double& r) : c(c), r(r) {}
};
istream& operator >> (istream& is, Circle& circle) { return is >> circle.c >> circle.r; }
ostream& operator << (ostream& os, Circle& circle) { return os << "(" << circle.c << "," << circle.r << ")"; }
 
Point project(const Segment& s, const Point& p) {
  Vector base = s.p2 - s.p1;
  double r = (p - s.p1) * base / norm(base);
  return s.p1 + base * r;
}
double getDistanceLP(const Line& l, const Point& p) {
  return abs((l.p2 - l.p1) ^ (p - l.p1)) / abs(l.p2 - l.p1);
}
Polygon getCrossPointCL(const Circle& c, const Line& l) {
  Polygon ps;
  Vector pr = project(l, c.c);
  if (sgn(getDistanceLP(l, c.c) - c.r) == 0) {
    ps.emplace_back(pr);
  } else {
    Vector e = (l.p2 - l.p1) / abs(l.p2 - l.p1);
    double base = sqrt(c.r * c.r - norm(pr - c.c));
    ps.emplace_back(pr + e * base);
    ps.emplace_back(pr - e * base);
  }
  return ps;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  int n;
  while (cin >> n, n) {
    vector<Circle> cs(n);
    for (int i = 0; i < n; i++) {
      cin >> cs[i];
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
      Segment s;
      cin >> s;
      bool safe = false;
      for (int j = 0; j < n; j++) {
        auto ps = getCrossPointCL(cs[j], s);
        for (auto p : ps) {
          Vector a = s.p1 - p, b = s.p2 - p;
          if (sgn(a * b) < 0) safe = true;
        }
      }
      cout << (safe ? "Safe" : "Danger") << endl;
    }
  }

  return 0;
}
