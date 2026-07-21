#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <sstream>
#include <cmath>
#include <climits>
#include <set>
#include <iostream>
#include <map>
#include <functional>
#include <cstdlib>
#include <numeric>
#include <queue>
#include <complex>
#include <sstream>
#include <stack>

using namespace std;

#define reep(i,f,n) for(int i=f; i<int(n); ++i)
#define rep(i,n) reep(i,0,n)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

const double EPS = 1e-8;
const double INF = 1e12;

// ½ÊãÌ_ExNg
typedef complex<double> P;
namespace std{
	bool operator< (const P& a, const P& b){
		return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
	}
}

// OÏ
double cross(const P& a, const P& b){
	return imag(conj(a)*b);
}

// àÏ
double dot(const P& a, const P& b){
	return real(conj(a)*b);
}

// ¼ü
struct L : public vector<P> {
	L(const P &a, const P &b){
		push_back(a);
		push_back(b);
	}
};

// ½p`
typedef vector<P> G;

// ~
struct C{
	P p;
	double r;
	C(){}
	C(const P& p, double r) : p(p), r(r) {}
};

P projection(const L& l, const P& p){
	double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
	return l[0] + t*(l[0]-l[1]);
}
bool intersectSP(const L& s, const P& p){
	return abs(s[0]-p) + abs(s[1]-p) - abs(s[1]-s[0]) < EPS;
}
double distanceSP(const L& s, const P& p){
	const P r = projection(s, p);
	if(intersectSP(s, r)) return abs(r - p);
	return min(abs(s[0]-p), abs(s[1]-p));
}

int main()
{
	int n;
	while(scanf("%d", &n), n){
		vector<C> cs(n);
		rep(i, n){
			scanf("%lf%lf%lf", &cs[i].p.real(), &cs[i].p.imag(), &cs[i].r);
		}
		
		int m;
		scanf("%d", &m);
		rep(i, m){
			P a, b;
			scanf("%lf%lf%lf%lf", &a.real(), &a.imag(), &b.real(), &b.imag());
			L l(a, b);

			bool visible = true;
			rep(i, n){
				bool inner = abs(l[0]-cs[i].p)<cs[i].r && abs(l[1]-cs[i].p)<cs[i].r;
				if(!inner && distanceSP(l, cs[i].p) - cs[i].r < EPS){
					visible = false;
					break;
				}
			}
			puts(visible ? "Danger" : "Safe");
		}
	}

	return 0;
}
