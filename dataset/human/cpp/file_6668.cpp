#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;
static const double EPS = 1e-8;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define sz(a) a.size()
#define all(a) a.begin(),a.end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define SS stringstream
#define DBG1(a) rep(_X,sz(a)){printf("%d ",a[_X]);}puts("");
#define DBG2(a) rep(_X,sz(a)){rep(_Y,sz(a[_X]))printf("%d ",a[_X][_Y]);puts("");}
#define bitcount(b) __builtin_popcount(b)
#define REP(i, s, e) for ( int i = s; i <= e; i++ )  

const double INF = 1e12;
typedef complex<double> P,point;
typedef vector<P> G,polygon;
namespace std {bool operator < (const P& a, const P& b) {return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);}}
double cross(const P& a, const P& b) {return imag(conj(a)*b);}
double dot(const P& a, const P& b) {return real(conj(a)*b);}
struct L : public vector<P> {L(const P &a, const P &b) {push_back(a); push_back(b);}};
struct C {P p; double r;C(const P &p, double r) : p(p), r(r) { }};
int ccw(P a, P b, P c) {b -= a; c -= a;if (cross(b, c) > 0)   return +1;if (cross(b, c) < 0)   return -1;if (dot(b, c) < 0) return +2;if (norm(b) < norm(c)) return -2;return 0;}

// Check Funcs //
bool intersectLL(const L &l, const L &m) {return abs(cross(l[1]-l[0], m[1]-m[0])) > EPS || abs(cross(l[1]-l[0], m[0]-l[0])) < EPS;}
bool intersectLS(const L &l, const L &s) {return cross(l[1]-l[0], s[0]-l[0])*cross(l[1]-l[0], s[1]-l[0]) < EPS;}
bool intersectLP(const L &l, const P &p) {return abs(cross(l[1]-p, l[0]-p)) < EPS;}
bool intersectSS(const L &s, const L &t) {return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 && ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;}
bool intersectSP(const L &s, const P &p) {return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0]) < EPS;}

// Where is Point in Polygon? //
#define curr(P, i) P[i]
#define next(P, i) P[(i+1)%P.size()]
enum { OUT, ON, IN };
int contains(const polygon& P, const point& p) {bool in = false;for (int i = 0; i < P.size(); ++i) {point a = curr(P,i) - p, b = next(P,i) - p;if (imag(a) > imag(b)) swap(a, b);if (imag(a) <= 0 && 0 < imag(b))if (cross(a, b) < 0) in = !in;if (cross(a, b) == 0 && dot(a, b) <= 0) return ON;}return in ? IN : OUT;}
// Area of Polygon //
double area2(const polygon& P) {double A = 0;for (int i = 0; i < P.size(); ++i)A += cross(curr(P, i), next(P, i));return A;}
// Totsuhou! Andrew's Monotone Chain //
vector<point> convex_hull(vector<point> ps) {int n = ps.size(), k = 0;sort(ps.begin(), ps.end());vector<point> ch(2*n);for (int i = 0; i < n; ch[k++] = ps[i++])while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--])while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;ch.resize(k-1);return ch;}

P projection(const L &l, const P &p) {double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);return l[0] + t*(l[0]-l[1]);}
P reflection(const L &l, const P &p) {return p + 2.0 * (projection(l, p) - p);}
double distanceLP(const L &l, const P &p) {return abs(p - projection(l, p));}
double distanceLL(const L &l, const L &m) {return intersectLL(l, m) ? 0 : distanceLP(l, m[0]);}
double distanceLS(const L &l, const L &s) {if (intersectLS(l, s)) return 0;return min(distanceLP(l, s[0]), distanceLP(l, s[1]));}
double distanceSP(const L &s, const P &p) {const P r = projection(s, p);if (intersectSP(s, r)) return abs(r - p);return min(abs(s[0] - p), abs(s[1] - p));}
double distanceSS(const L &s, const L &t) {if (intersectSS(s, t)) return 0;  return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])),min(distanceSP(t, s[0]), distanceSP(t, s[1])));}
P crosspoint(const L &l, const L &m) {double A = cross(l[1] - l[0], m[1] - m[0]);double B = cross(l[1] - l[0], l[1] - m[0]);if (abs(A) < EPS && abs(B) < EPS) return m[0];return m[0] + B / A * (m[1] - m[0]);}

P getPedal(L l, P p){
	double A;
	if(abs(l[1].real()-l[0].real()) < EPS){
		return P(l[1].real(),p.imag());
	}else{
		A = (l[1].imag()-l[0].imag())/(l[1].real()-l[0].real());
	}
	double a = -A , b = 1 , c = A*l[0].real() - l[0].imag();
	double t = (a*p.real() + b*p.imag() + c)/(a*a+b*b);
	return p-t * P(a,b);
}

vector<P> crosspointCL(const L l, const C c){
	vector<P> ret;
	P p = getPedal(l,c.p);

	if( (abs(c.p-l[0]) < c.r+EPS && abs(c.p-l[1]) < c.r+EPS) &&
		abs(l[1]-l[0]) < c.r+EPS
	){
			for(int i=0;i<3;i++)ret.push_back(P(0,0));
			return ret;
	}
	
	if(	abs(p-c.p) > c.r+EPS)return ret;
	P e = P((l[1]-l[0])/abs(l[1]-l[0]));
	double S = sqrt(c.r*c.r-abs(p-c.p)*abs(p-c.p));
	ret.push_back(p+S*e);
	ret.push_back(p-S*e);
	return ret;
}
int main(){
	int n;
	while(cin >> n , n){
		vector<C> wall;
		rep(i,n){
			double x,y,r;
			cin >> x >> y >> r;
			wall.push_back(C(P(x,y),r));
		}
		int m; cin >> m;
		rep(i,m){
			double x1,y1,x2,y2;
			cin >> x1 >> y1 >> x2 >> y2;
			P hero(x1,y1) , enemy(x2,y2);
			//cout << hero << " " << enemy << endl;
			L line(hero,enemy);
			bool f = false;
			rep(i,wall.size()){
				vector<P> get = crosspointCL(line,wall[i]);
				if(get.size() != 3){
					rep(j,get.size()){
						//cout << get[j] << endl;
						if(min(x1,x2) <= get[j].real() && get[j].real() <= max(x1,x2) && 
						   min(y1,y2) <= get[j].imag() && get[j].imag() <= max(y1,y2)
						){
							f = true;
						}
					}
				}
			}
			cout << (f?"Safe":"Danger") << endl;
		}
	}
}
