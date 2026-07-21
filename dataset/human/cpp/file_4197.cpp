#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <istream>
#include <ostream>

#include <cstdlib>
#include <cmath>
#include <cstdio>

using namespace std;

#define fi first
#define se second
#define mkp make_pair
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define rep(i,n) for(ll i=0; i < (n); ++i)
#define rrep(i,n) for(ll i=((n)-1); i >= 0; --i)

#define OPLT(T) bool operator<(const T & lop_, const T & rop_)
#define OPEQ(T) bool operator==(const T & lop_, const T & rop_)

#define x first
#define y second

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

istream& operator>>(istream& istr, __float128& obj) { double d; istr >> d; obj = d; return istr; };
ostream& operator<<(ostream& ostr, __float128& obj) { ostr << static_cast<double>(obj); return ostr; };

struct C {
	pdd p;
	double r;
	C() {}
	C(pdd p_, double  r_) {
		p = p_;
		r = r_;
	}
};

double dist(C a, C b) {
	pdd aa, bb;
	aa = a.p; bb = b.p;
	double d;
	d = sqrt((aa.x - bb.x) * (aa.x - bb.x) + (aa.y - bb.y) * (aa.y - bb.y));
	return max(0.0, d - a.r - b.r);
}

vector<vector<pair<int,double> > >  E;
vector<double > cost;
const double INF = 4e9;

int main() {
	vector<C> v;
	pdd s, t;
	int N;
	cin >> s.fi >> s.se >> t.fi >> t.se;
	cin >> N;
	v.push_back(C(s,0)); v.push_back(C(t,0));
	rep(i,N) {
		pdd tmp;
		double r;
		cin >> tmp.x >> tmp.y >> r;
		v.push_back(C(tmp,r));
	}
	E.resize(N+2);
	rep(i,v.size()) {
		for(int j = i+1; j < v.size(); j++) {
			double d;
			d = dist(v[i], v[j]);
			E[i].push_back(mkp(j,d));
			E[j].push_back(mkp(i,d));
		}
	}
	cost.resize(N+2);
	rep(i,N+2) cost[i] = INF;
	priority_queue<pair<double,int> > q;
	cost[0] = 0;
	q.push(mkp(0,0));
	while(q.size()) {
		pair<double, int> a;
		a = q.top(); q.pop();
		for(int i = 0; i < E[a.se].size(); i++) {
			double b;
			b = -a.fi + E[a.se][i].se;
			if(b < cost[E[a.se][i].fi]) {
				cost[E[a.se][i].fi] = b;
				q.push(mkp(-b, E[a.se][i].fi));
			}
		}
	}
	printf("%.10f\n", cost[1]);
	return 0;
}
