#include<iostream>
#include<cmath>
using namespace std;
struct Point { long double px, py; };
struct Segment { Point p1, p2; };
Point Minus(const Point& a, const Point& b) { return Point{ a.px - b.px,a.py - b.py }; }
long double norm(const Point& a) { return a.px * a.px + a.py * a.py; }
long double abs(const Point& a) { return sqrtl(norm(a)); }
long double dot(const Point& a, const Point& b) { return a.px * b.px + a.py * b.py; }
long double crs(const Point& a, const Point& b) { return a.px * b.py - a.py * b.px; }
long double dst(const Segment& a, const Point& b) { return dot(Minus(a.p2, a.p1), Minus(b, a.p1)) < 0.0 ? abs(Minus(b, a.p1)) : (dot(Minus(a.p1, a.p2), Minus(b, a.p2)) < 0.0 ? abs(Minus(b, a.p2)) : abs(crs(Minus(a.p2, a.p1), Minus(b, a.p1)) / abs(Minus(a.p2, a.p1)))); }
long double dst(const Point& a, const Point& b) { return abs(Minus(b, a)); }

int n, m; Point V, W, x[100]; long double r[100];
int main() {
	while (true) {
		cin >> n; if (n == 0)break;
		for (int i = 0; i < n; i++) { cin >> x[i].px >> x[i].py >> r[i]; }
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> V.px >> V.py >> W.px >> W.py;
			bool OK = false;
			for (int j = 0; j < n; j++) {
				if (dst(V, x[j]) <= r[j] && dst(W, x[j])>r[j])OK = true;
				else if (dst(V, x[j])>r[j] && dst(W, x[j]) <= r[j])OK = true;
				else if (dst(V, x[j])>r[j] && dst(W, x[j]) > r[j]) {
					if (dst(Segment{ V,W }, x[j]) <= r[j])OK = true;
				}
			}
			if (OK == true)cout << "Safe" << endl; else cout << "Danger" << endl;
		}
	}
	return 0;
}
