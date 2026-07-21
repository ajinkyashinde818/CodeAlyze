#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
#include <bitset>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef pair<ll,ll> P;
typedef vector<P> vpl;
typedef tuple<ll,ll,ll> tapu;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int MAX = 510000;
ll dy[8] = {0,1,0,-1,1,-1,1,-1};
ll dx[8] = {1,0,-1,0,1,-1,-1,1};
const double pi = acos(-1);
const double eps = 1e-7;
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){
	if(a>b){
		a = b; return true;
	}
	else return false;
}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){
	if(a<b){
		a = b; return true;
	}
	else return false;
}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << endl;}
template<typename T1,typename T2,typename T3> inline void print3(T1 a, T2 b, T3 c){
	cout << a << " " << b << " " << c << endl;
}
const int mod = 1e9 + 7;
//const int mod = 998244353;

double dist(ll x1, ll y1, ll x2, ll y2){
	return sqrtl((x1-x2)*(x1-x2)+(y2-y1)*(y2-y1));
}
typedef pair<double,ll> pd;

int main(){
	double xs,ys,xt,yt; cin >> xs >> ys >> xt >> yt;
	ll n; cin >> n;
	vd x(n+2),y(n+2),r(n+2);
	x[0] = xs; y[0] = ys; r[0] = 0;
	x[n+1] = xt; y[n+1] = yt; r[n+1] = 0;
	REP(i,1,n+1) cin >> x[i] >> y[i] >> r[i];
	vector<vd> d(n+2,vd(n+2,linf));
	rep(i,n+2){
		rep(j,n+2){
			if(i==j) d[i][j] = 0;
			else{
				d[i][j] = max(0.0,dist(x[i],y[i],x[j],y[j])-r[i]-r[j]);
			}
		}
	}
	vd dd(n+2,linf);
	dd[0] = 0.0;
	priority_queue<pd,vector<pd>,greater<pd>> pq;
	pq.emplace(0,0);
	while(!pq.empty()){
		pd p = pq.top(); pq.pop();
		ll u = p.second;
		rep(v,n+2){
			if(v==u) continue;
			if(dd[v] <= dd[u] + d[u][v]) continue;
			dd[v] = dd[u] + d[u][v];
			pq.emplace(dd[v],v);
		}
	}
	printf("%.10f\n",dd[n+1]);
}
