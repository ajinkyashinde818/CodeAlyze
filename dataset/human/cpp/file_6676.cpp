#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Point {
public:
	long double px, py;
	Point() : px(0), py(0) {};
	Point(long double px_, long double py_) : px(px_), py(py_) {};
	bool operator==(const Point& p) const { return px == p.px && py == p.py; }
	bool operator!=(const Point& p) const { return px != p.px || py != p.py; }
	bool operator<(const Point& p) const { return px < p.px ? true : (px == p.px && py < p.py); }
	bool operator>(const Point& p) const { return px > p.px ? true : (px == p.px && py > p.py); }
	bool operator<=(const Point& p) const { return !(Point(px, py) > p); }
	bool operator>=(const Point& p) const { return !(Point(px, py) < p); }
	Point operator+(const Point& p) const { return Point(px + p.px, py + p.py); }
	Point operator-(const Point& p) const { return Point(px - p.px, py - p.py); }
	Point operator/(long double d) const { return Point(px / d, py / d); }
	friend Point operator*(const Point p, long double d) { return Point(p.px * d, p.py * d); }
	friend Point operator*(long double d, const Point& p) { return p * d; }
	Point& operator+=(const Point& p1) { px += p1.px, py += p1.py; return *this; }
	Point& operator-=(const Point& p1) { px -= p1.px, py -= p1.py; return *this; }
	Point& operator*=(long double d) { px *= d, py *= d; return *this; }
	Point& operator/=(long double d) { px /= d, py /= d; return *this; }
};
class Segment {
public:
	Point p1, p2;
	Segment() : p1(Point()), p2(Point()) {};
	Segment(Point p1_, Point p2_) : p1(p1_), p2(p2_) {};
	Segment(long double p1x, long double p1y, long double p2x, long double p2y) : p1(Point(p1x, p1y)), p2(Point(p2x, p2y)) {};
	bool operator==(const Segment& s) const { return (p1 == s.p1 && p2 == s.p2) || (p1 == s.p2 && p2 == s.p1); }
	bool operator!=(const Segment& s) const { return !(Segment(p1, p2) == s); }
};
long double norm(const Point& a) { return a.px * a.px + a.py * a.py; }
long double abs(const Point& a) { return sqrtl(norm(a)); }
long double arg(const Point& a) { return atan2l(a.py, a.px); }
long double dot(const Point& a, const Point& b) { return a.px * b.px + a.py * b.py; }
long double crs(const Point& a, const Point& b) { return a.px * b.py - a.py * b.px; }
long double dst(const Point& a, const Point& b) { return abs(b - a); }
long double dst(const Segment& a, const Point& b) { return dot(a.p2 - a.p1, b - a.p1) < 0.0 ? abs(b - a.p1) : (dot(a.p1 - a.p2, b - a.p2) < 0.0 ? abs(b - a.p2) : abs(crs(a.p2 - a.p1, b - a.p1) / abs(a.p2 - a.p1))); }
int n, q, r[109]; Point c[109], s, t;
int main() {
	while (cin >> n, n) {
		for (int i = 0; i < n; i++) {
			cin >> c[i].px >> c[i].py >> r[i];
		}
		cin >> q;
		while(q--) {
			cin >> s.px >> s.py >> t.px >> t.py;
			bool flag = false;
			for (int i = 0; i < n; i++) {
				long double z1 = dst(s, c[i]), z2 = dst(t, c[i]);
				long double z3 = dst(Segment(s, t), c[i]);
				bool f1 = (z1 > r[i]), f2 = (z2 > r[i]);
				if (f1 != f2) flag = true;
				if (f1 && f2 && z3 <= r[i]) flag = true;
			}
			cout << (flag ? "Safe" : "Danger") << endl;
		}
	}
	return 0;
}
