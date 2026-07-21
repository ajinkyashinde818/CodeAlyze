#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <array>
#include <map>
#include <queue>
#include <limits.h>
#include <set>
#include <bitset>
#include <stack>
#include <cstdlib>
#include <complex>
#include <unordered_map>
#define REP(i,n) for(int i = 0; n > i; i++)
#define MODU 33
#define Range(x,a,b) ((a) <= (x) && (x) <= (b))
#define POWT(x) ((x)*(x))
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef vector<int> Ivec;
typedef pair<int, int> pii;
typedef long long int ll;

////???????????¬////
const double EPS = 1e-8;
const double INF = 1e12;
typedef complex<double> Pt;//???
namespace std {
	bool operator < (const Pt& a, const Pt& b) {
		return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
	}
}
double cross(const Pt& a, const Pt& b) {
	return imag(conj(a)*b);
}
double dot(const Pt& a, const Pt& b) {
	return real(conj(a)*b);
}

struct Ln : public vector<Pt> {//???
	Ln(const Pt &a, const Pt &b) {
		push_back(a); push_back(b);
	}
};

typedef vector<Pt> Pol;//????§???¢

struct Cir {//???
	Pt p; double r;
	Cir(const Pt &p, double r) : p(p), r(r) { }
};

int ccw(Pt a, Pt b, Pt c) {
	b -= a; c -= a;
	if (cross(b, c) > 0)   return +1;       // counter clockwise
	if (cross(b, c) < 0)   return -1;       // clockwise
	if (dot(b, c) < 0)     return +2;       // c--a--b on line
	if (norm(b) < norm(c)) return -2;       // a--b--c on line
	return 0;
}

Pt projection(const Ln &l, const Pt &p) {
	double t = dot(p - l[0], l[0] - l[1]) / norm(l[0] - l[1]);
	return l[0] + t*(l[0] - l[1]);
}
bool intersectSP(const Ln &s, const Pt &p) {//????????????
	return abs(s[0] - p) + abs(s[1] - p) - abs(s[1] - s[0]) < EPS; // triangle inequality
}
double distanceSP(const Ln &s, const Pt &p) {
	const Pt r = projection(s, p);
	if (intersectSP(s, r)) return abs(r - p);
	return min(abs(s[0] - p), abs(s[1] - p));
}

bool intersectCL(const Ln &s, const Cir &c) {
	double dis = distanceSP(s, c.p);
	return dis <= c.r;
}
double distancePP(const Pt &p, const Pt &q) {
	return hypot(p.real() - q.real(), p.imag() - q.imag());
}
bool insideCir(Pt &p, Cir &c) {
	return distancePP(p, c.p) <= c.r;
}
int main() {
	int n, m;
	while (scanf("%d", &n)) {
		if (n == 0)
			return 0;
		vector<Cir> walls;
		REP(i, n) {
			double px, py, r;
			scanf("%lf %lf %lf", &px, &py, &r);
			walls.push_back({ {px,py},r });
		}

		scanf("%d", &m);
		REP(i, m) {
			Pt t, s;
			double x, y;
			scanf("%lf %lf", &x, &y);
			t = { x,y };
			scanf("%lf %lf", &x, &y);
			s = { x,y };

			bool f = 0;
			REP(j, n) {
				f = intersectCL({ t,s }, walls[j]);
				if (f) {
					if (insideCir(t, walls[j]) && insideCir(s, walls[j]))
						f = 0;
					else
						break;
				}
			}
			if (f) {
				printf("Safe\n");
			}
			else
				printf("Danger\n");
		}
	}
	return 0;
}
