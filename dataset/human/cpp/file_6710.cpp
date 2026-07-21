#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<utility>
#include<numeric>
#include<algorithm>
#include<bitset>
#include<complex>
#include<stack>

using namespace std;

typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<string> vstring;

template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

#define rep(i,n) for(int i=0;i<(n);i++)
#define rep0(i,n) for(i=0;i<(n);i++)
#define repn(i,m,n) for(int i=(m);i<=(n);i++)
#define all(n) n.begin(),n.end()
#define mp make_pair
#define PUTLINE cout<<__LINE__<<endl;

const double EPS = 1e-10;
const double PI = acos(-1.0);

const int dx[]={1,-1,0,0,1,1,-1,-1,0};
const int dy[]={0,0,1,-1,1,-1,1,-1,0};

int sig(double r) { return (r < -EPS) ? -1 : (r > +EPS) ? +1 : 0; }
struct Pt {
	double x, y;
	Pt() {}
	Pt(double x, double y) : x(x), y(y) {}
	Pt operator+(const Pt &a) const { return Pt(x + a.x, y + a.y); }
	Pt operator-(const Pt &a) const { return Pt(x - a.x, y - a.y); }
	Pt operator*(const Pt &a) const { return Pt(x * a.x - y * a.y, x * a.y + y * a.x); }
	Pt operator-() const { return Pt(-x, -y); }
	Pt operator*(const double &k) const { return Pt(x * k, y * k); }
	Pt operator/(const double &k) const { return Pt(x / k, y / k); }
	double abs() const { return sqrt(x * x + y * y); }
	double abs2() const { return x * x + y * y; }
	double arg() const { return atan2(y, x); }
	double dot(const Pt &a) const { return x * a.x + y * a.y; }
	double det(const Pt &a) const { return x * a.y - y * a.x; }
	bool operator<(const Pt &a) const { return (x != a.x) ? (x < a.x) : (y < a.y); }
	bool operator==(const Pt &a) const { return (sig(x - a.x) == 0 && sig(y - a.y) == 0); }
};
ostream &operator<<(ostream &os, const Pt &a) { os << "(" << a.x << ", " << a.y << ")"; return os; }
double tri(Pt a, Pt b, Pt c) { return (b - a).det(c - a); }

Pt proj(Pt a, Pt b) { return a * a.dot(b) / a.abs2(); }

Pt perp(Pt a, Pt b, Pt c) { return a + proj(b - a, c - a); }

Pt refl(Pt a, Pt b, Pt c) { return perp(a, b, c) * 2 - c; }

int iSP(Pt a, Pt b, Pt c) {
	int s = sig((b - a).det(c - a));
	if (s) return s;
	if (sig((b - a).dot(c - a)) < 0) return -2; // c-a-b
	if (sig((a - b).dot(c - b)) < 0) return +2; // a-b-c
	return 0;
}

int iLL(Pt a, Pt b, Pt c, Pt d) {
	if (sig((b - a).det(d - c))) return 1; // intersect
	if (sig((b - a).det(c - a))) return 0; // parallel
	return -1; // correspond
}

bool iLS(Pt a, Pt b, Pt c, Pt d) {
	return (sig(tri(a, b, c)) * sig(tri(a, b, d)) <= 0);
}

bool iSS(Pt a, Pt b, Pt c, Pt d) {
	return (iSP(a, b, c) * iSP(a, b, d) <= 0 && iSP(c, d, a) * iSP(c, d, b) <= 0);
}

bool iSSstrict(Pt a, Pt b, Pt c, Pt d) {
	return (sig(tri(a, b, c)) * sig(tri(a, b, d)) < 0 && sig(tri(c, d, a)) * sig(tri(c, d, b)) < 0);
}

Pt pLL(Pt a, Pt b, Pt c, Pt d) {
	b = b - a; d = d - c;
	return a + b * (c - a).det(d) / b.det(d);
}

double dLP(Pt a, Pt b, Pt c) {
	return abs(tri(a, b, c)) / (b - a).abs();
}

double dSP(Pt a, Pt b, Pt c) {
	if (sig((b - a).dot(c - a)) <= 0) return (c - a).abs();
	if (sig((a - b).dot(c - b)) <= 0) return (c - b).abs();
	return abs(tri(a, b, c)) / (b - a).abs();
}

double dLL(Pt a, Pt b, Pt c, Pt d) {
	return iLL(a, b, c, d) ? 0 : dLP(a, b, c);
}

double dLS(Pt a, Pt b, Pt c, Pt d) {
	return iLS(a, b, c, d) ? 0 : min(dLP(a, b, c), dLP(a, b, d));
}

double dSS(Pt a, Pt b, Pt c, Pt d) {
	return iSS(a, b, c, d) ? 0 : min(min(dSP(a, b, c), dSP(a, b, d)), min(dSP(c, d, a), dSP(c, d, b)));
}

int iCC(Pt a, double r, Pt b, double s) {
	double d = (b - a).abs();
	if (sig(d) == 0 && sig(r - s) == 0) return -1; // correspond
	if (sig(r - s - d) > 0) return +2; // r > s
	if (sig(s - r - d) > 0) return -2; // s > r
	return (sig(r + s - d) >= 0) ? 1 : 0;
}

bool iCS(Pt a, double r, Pt b, Pt c) {
	return (sig(r - dSP(b, c, a)) >= 0 && sig(r - max((b - a).abs(), (c - a).abs())) <= 0);
}

pair<Pt,Pt> pCC(Pt a, double r, Pt b, double s) {
	double d = (b - a).abs();
	double x = (d * d + r * r - s * s) / (d * 2);
	Pt e = (b - a) / d, w = e * Pt(0, 1) * sqrt(max(r * r - x * x, 0.0));
	return mp(a + e * x - w, a + e * x + w);
}

pair<Pt,Pt> pCL(Pt a, double r, Pt b, Pt c) {
	Pt h = perp(b, c, a);
	double d = (h - a).abs();
	double y = sqrt(max(r * r - d * d, 0.0));
	Pt e = (c - b) / (c - b).abs();
	return mp(h - e * y, h + e * y);
}
/*
pair<Pt,Pt> tCP(Pt a, double r, Pt b) {
	double d2 = (b - a).norm();
	double x = sqrt(max(d2 - r * r, 0.0));
	Pt h = a + (b - a) * (r * r / d2);
	Pt w = (b - a) * Pt(0, 1) * (x * r / d2);
	return mp(h - w, h + w);
}
*/
double aCC(Pt a, double r, Pt b, double s) {
	double d = (a - b).abs();
	if (sig(r - s - d) >= 0) return s * s * PI;
	if (sig(s - r - d) >= 0) return r * r * PI;
	if (sig(r + s - d) <= 0) return 0;
	double x = (d * d + r * r - s * s) / (d * 2);
	double h = sqrt(r * r - x * x);
	return r * r * atan2(h, x) + s * s * atan2(h, d - x) - d * h;
}

int convexhull(int n, Pt p[], Pt q[]) {
	int m = 0, i, r;
	sort(p, p + n);
	for (i = 0; i < n; q[m++] = p[i++]) for (; m > 1 && sig(tri(q[m - 2], q[m - 1], p[i])) <= 0; --m);
	for (i = n - 2, r = m; i >= 0; q[m++] = p[i--]) for (; m > r && sig(tri(q[m - 2], q[m - 1], p[i])) <= 0; --m);
	return m - 1;
}

int convexcut(int n, Pt p[], Pt a, Pt b, Pt q[]) {
	int m = 0, i;
	p[n] = p[0];
	for (i = 0; i < n; ++i) {
		if (sig(tri(a, b, p[i])) >= 0) q[m++] = p[i];
		if (sig(tri(a, b, p[i])) * sig(tri(a, b, p[i + 1])) < 0) q[m++] = pLL(a, b, p[i], p[i + 1]);
	}
	q[m] = q[0];
	return m;
}

int sGP(int n, Pt p[], Pt a) {
	int side = -1, i;
	p[n] = p[0];
	for (i = 0; i < n; ++i) {
		Pt p0 = p[i] - a, p1 = p[i + 1] - a;
		if (sig(p0.det(p1)) == 0 && sig(p0.dot(p1)) <= 0) return 0;
		if (p0.y > p1.y) swap(p0, p1);
		if (sig(p0.y) <= 0 && 0 < sig(p1.y) && sig(p0.det(p1)) > 0) side = -side;
	}
	return side;
}

int sVP(int n, Pt p[], Pt a) {
	Pt o = (p[0] + p[n / 2]) / 2;
	int lo = 0, ho = n, fl = sig(tri(o, p[lo], a));
	p[n] = p[0];
	for (; lo + 1 < ho; ) {
		int mo = (lo + ho) / 2, fm = sig(tri(o, p[mo], a));
		(fl - fm - sig(tri(o, p[lo], p[mo])) < 0) ? (lo = mo, fl = fm) : ho = mo;
	}
	return sig(tri(p[lo], p[ho], a));
}

int sAP(Pt a, Pt b, Pt c) {
	return sig(a.det(c)) - sig(b.det(c)) - sig(a.det(b));
}

int s_a[1000], s_b[1000], s_ab[1000];
bool iGSstrict(int n, Pt p[], Pt a, Pt b) {
	int i;
	p[n] = p[0];
	p[n + 1] = p[1];
	if (sGP(n, p, a) > 0 || sGP(n, p, b) > 0) return 1;
	for (i = 0; i <= n; ++i) {
		s_a[i] = sig(tri(p[i], p[i + 1], a));
		s_b[i] = sig(tri(p[i], p[i + 1], b));
		s_ab[i] = sig(tri(a, b, p[i]));
	}
	for (i = 0; i < n; ++i) {
		if (s_a[i] * s_b[i] < 0 && s_ab[i] * s_ab[i + 1] < 0) return 1;
	}
	for (i = 0; i < n; ++i) {
		if (s_a[i] == 0 && s_b[i] > 0 && sig((a - p[i]).dot(a - p[i + 1])) < 0) return 1;
		if (s_b[i] == 0 && s_a[i] > 0 && sig((b - p[i]).dot(b - p[i + 1])) < 0) return 1;
	}
	for (i = 0; i < n; ++i) if (s_ab[i + 1] == 0 && sig((p[i + 1] - a).dot(p[i + 1] - b)) <= 0) {
		if (!(p[i + 1] == a) && sAP(p[i + 2] - p[i + 1], p[i] - p[i + 1], a - p[i + 1]) > 0) return 1;
		if (!(p[i + 1] == b) && sAP(p[i + 2] - p[i + 1], p[i] - p[i + 1], b - p[i + 1]) > 0) return 1;
	}
	return 0;
}

double quartercut(double r, double x, double y) {
	if (x * x + y * y >= r * r) return 0;
	double xx = sqrt(r * r - y * y), yy = sqrt(r * r - x * x);
	return (r * r * (atan2(yy, x) - atan2(y, xx)) - (xx - x) * y - x * (yy - y)) / 2;
}

Pt circumcenter(Pt a, Pt b, Pt c) {
	Pt bc = c - b, ca = a - c, ab = b - a;
	return (b + c - bc * Pt(0, 1) * ca.dot(ab) / ca.det(ab)) / 2;
}

int main() {
	int n;
	Pt w[110],t,s;
	double r[110];
	while(n=in()){
		rep(i,n)cin>>w[i].x>>w[i].y>>r[i];
		int m=in();
		rep(i,m){
			cin>>t.x>>t.y>>s.x>>s.y;
			bool visiable=true;
			rep(i,n)if(iCS(w[i],r[i],t,s))visiable=false;
			if(visiable)cout<<"Danger\n";
			else cout<<"Safe\n";
		}
	}
	return 0;
}
