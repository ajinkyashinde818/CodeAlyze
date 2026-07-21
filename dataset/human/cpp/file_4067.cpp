//#pragma comment(linker, "/STACK:1024000000,1024000000")
/* vim: set fdm=marker */
//{{{
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int iinf = 0x7fffffff;
const ll linf = ~(1LL<<63);
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<ll, int> mli;
typedef map<ll, ll> mll;
template<typename T>
inline T gcd(T a, T b) {
	if(a < 0) return gcd(-a, b);
	if(b < 0) return gcd( a,-b);
	if(a < b) return gcd(b, a);
	if(b == 0) return a;
	return gcd(b, a%b);
}

ll qpow(ll a, ll n, ll mod) {
	a %= mod;
	ll ans = 1LL;
	while(n) {
		if(n & 1) ans = (ans*a % mod);
		a = (a*a % mod);
		n >>= 1;
	}
	return ans;
}

inline ll rev(ll a, ll p) {
	return qpow(a, p - 2, p);
}

#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define rep(x, st, en) for(int x = st; x < en; x++)
#define rer(x, st, en) for(int x = st; x >= en; x--)
#define pb push_back
#define mp make_pair
#define dbgm(msg, var) cerr<<#msg<<" "<<#var<<" = "<<var<<endl; 
#define dbg(var) cerr<<#var<<" = "<<var<<endl;
#define X first
#define Y second
// build prefix sum
template<typename T>
inline void BPS(T* DST, T* SRC, int N, int s = 0) {
	DST[s] = SRC[s];
	rep(i, 1, N) DST[s + i] = DST[s + i - 1] + SRC[s + i];
}
inline int in() { int x; cin>>x; return x; }
#ifdef ALNDBG
namespace alndbg {
	clock_t s, e;
}
#endif

inline void tic() {
#ifdef ALNDBG
	alndbg::s = clock();
#endif
}

inline void toc() {
#ifdef ALNDBG
	alndbg::e = clock();
	cerr<<1000.0 * (alndbg::e - alndbg::s) / CLOCKS_PER_SEC<<" ms"<<endl;
#endif
}

//}}}

// -------------------- Spliters ------------------------
const int maxn = 1010;

struct Circle {
	ll x, y;
	ll r;
} ps, pt;

vector<Circle> pts;
struct Edge {
	int to;
	double dis;
	bool operator<(const Edge& e) const {
		return dis > e.dis;
	}
};
vector<Edge> E[maxn];

double dis(Circle& u, Circle& v) {
	double d1 = sqrt((u.x - v.x) * (u.x - v.x) + (u.y - v.y) * (u.y - v.y));
	d1 -= u.r + v.r;
	return max(0.0, d1);
}

double dijkstra(int s, int t) {
	double dist[maxn];
	dist[s] = 0;
	rep(i, 1, maxn) dist[i] = 1e10;
	priority_queue<Edge> pq;
	pq.push({s, 0});
	while(!pq.empty()) {
		Edge t = pq.top(); pq.pop();
		if(t.dis > dist[t.to]) continue;
		for(auto& e : E[t.to]) {
			if(t.dis + e.dis < dist[e.to]) {
				dist[e.to] = t.dis + e.dis;
				pq.push({e.to, dist[e.to]});
			}
		}
	}
	return dist[t];
}


int main() {
	ios::sync_with_stdio(0);
	cin>>ps.x>>ps.y>>pt.x>>pt.y;
	ps.r = 0; pt.r = 0;
	pts.pb(ps);
	int N;
	cin>>N;
	rep(i, 0, N) {
		Circle c;
		cin>>c.x>>c.y>>c.r;
		pts.push_back(c);
	}
	pts.pb(pt);
	rep(i, 0, pts.size()) {
		rep(j, i + 1, pts.size()) {
			E[i].pb({j, dis(pts[i], pts[j])});
			E[j].pb({i, dis(pts[i], pts[j])});
		}
	}
	cout<<fixed<<setprecision(12)<<dijkstra(0, N + 1)<<endl;
	return 0;
}
// --USE C++11
// *-USE O2
