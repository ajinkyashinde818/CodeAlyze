#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
#include <ctime>
#include <complex>
  
using namespace std;
  
#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define pb push_back
#define mp make_pair
#define all(r) r.begin(),r.end()
#define rall(r) r.rbegin(),r.rend()
#define fi first
#define se second
#define println(X) cout<<X<<endl;
#define DBG(X) cout<<#X<<" : "<<X<<endl;
  
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
const double EPS = 1e-8;
const double INF = 1e18;

struct P
{
	double x, y;
};

struct C
{
	P p;
	double r;
};

double distPP(const P& p1, const P& p2){
	return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

double distPC(const P& p, const C& c){
	return max(0.0, distPP(p, c.p) - c.r);
}

double distCC(const C& c1, const C& c2){
	return max(0.0, distPP(c1.p, c2.p)-(c1.r+c2.r));
}

struct Edge
{
	int to;
	double cost;
};

vector<Edge> es[1010];
double d[1010];

int main(){
	P s, t;
	cin>>s.x>>s.y>>t.x>>t.y;
	int n;
	cin>>n;
	vector<C> c(n);
	rep(i, n) cin>>c[i].p.x>>c[i].p.y>>c[i].r;
	es[n].pb({n+1, distPP(s, t)});
	es[n+1].pb({n, distPP(s, t)});
	rep(i, n){
		es[n].pb({i, distPC(s, c[i])});
		es[i].pb({n, distPC(s, c[i])});
		es[n+1].pb({i, distPC(t, c[i])});
		es[i].pb({n+1, distPC(t, c[i])});
		rep(j, n) if(j != i) es[i].pb({j, distCC(c[i], c[j])});
	}
	auto dijkstra = [&]{
		typedef pair<double, int> P;
		priority_queue<P, vector<P>, greater<P> > q;
		P p;
		q.push({0.0, n});
		rep(i, 1010) d[i] = INF;
		while(!q.empty()){
			p = q.top(); q.pop();
			int from = p.se;
			double c = p.fi;
			for(auto& e : es[from]){
				int to = e.to;
				double cost = c + e.cost;
				if(d[to] <= cost) continue;
				d[to] = cost;
				q.push({cost, to});
			}
		}
	};
	dijkstra();
	printf("%.15lf\n", d[n+1]);
}
