// see https://github.com/LumaKernel/vimfiles/tree/master/snippets/cp-cpp/temp.snip
/// --- .lumrc Template {{{ ///
// #define DEBUG
// #define assert(...)
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using P = tuple<ll, ll>;
using P3 = tuple<ll, ll, ll>;
using VI = vector<int>;
using VL = vector<ll>;
using VVI = vector<VI>;
using VVL = vector<VL>;
using VP = vector<P>;
using VS = vector<string>;

#define omajinai ios::sync_with_stdio(false),cin.tie(0)

#define FOR(i,a,b) for(int i=int(a);i<int(b);++i)
#define FORI(i,a,b) for(int i=int(a);i<=int(b);++i)
#define REP(i,n) FOR(i,0,n)
#define REPI(i,n) FORI(i,0,n)
#define RFOR(i,a,b) for(int i=int(b)-1;i>=int(a);--i)
#define RFORI(i,a,b) for(int i=int(b);i>=int(a);--i)
#define RREP(i,n) RFOR(i,0,n)
#define RREPI(i,n) RFORI(i,0,n)

#define ALL(a) begin(a),end(a)
#define UNIQUE(a) (a).erase(unique(ALL(a)),(a).end())
#define PB push_back
#define EACH(i,c) REP(i,(c).size())
#define REACH(i,c) RREP(i,(c).size())
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort(ALL(c))

#define BR cout<<"\n";

#ifdef DEBUG
#define dump(...) cerr<<"["<<__LINE__<< "] "<<#__VA_ARGS__<<" = "<<make_tuple(__VA_ARGS__)<<"\n";
#else
#define dump(...)
#endif

#define YES(x) cout<<((x)?"YES":"NO")<<"\n";
#define Yes(x) cout<<((x)?"Yes":"No")<<"\n";
#define yes(x) cout<<((x)?"yes":"no")<<"\n";

int __int_temp; ll __ll_temp; string __string_temp;
#define oini (omajinai, cin>>__int_temp, __int_temp)
#define oinl (omajinai, cin>>__ll_temp, __ll_temp)
#define oins (omajinai, cin>>__string_temp, __string_temp)
#define ini (cin>>__int_temp, __int_temp)
#define inl (cin>>__ll_temp, __ll_temp)
#define ins (cin>>__string_temp, __string_temp)

#define isInside(y,x) (0<=(y)&&(y)<h&&0<=(x)&&(x)<w)

#define fi(x) (get<0>(x))
#define se(x) (get<1>(x))
#define th(x) (get<2>(x))
#define fo(x) (get<3>(x))
#define fif(x) (get<4>(x))

template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '{'; EACH(i, v) o << v[i] << (i != (int)v.size()-1 ? ", " : ""); o << "}";  return o; }

template<int n, class...T> typename enable_if<(n>=sizeof...(T))>::type _ot(ostream &, tuple<T...> const &){}
template<int n, class...T> typename enable_if<(n< sizeof...(T))>::type _ot(ostream & os, tuple<T...> const & t){ os << (n==0?"":", ") << get<n>(t); _ot<n+1>(os, t); }
template<class...T> ostream & operator<<(ostream & os, tuple<T...> const & t){ _ot<0>(os, t); return os; }

template <typename T> inline void smax(T &a, T b) { a = a > b ? a : b; }
template <typename T> inline void smin(T &a, T b) { a = a < b ? a : b; }

template<typename T> inline int intlog2(T x);
template<> inline int intlog2(int x) { return x == 0 ? 0 : 32 - __builtin_clz(x); }
template<> inline int intlog2(ll x) { return x == 0 ? 0 : 64 - __builtin_clzll(x); }

constexpr double PI = acos(-1);

/// }}}--- ///

constexpr int INF = 1e9+1;
constexpr ll LINF = 1e18+1;
constexpr int MOD = 1e9+7;

// EPS
constexpr double EPS = 1e-9;
/// --- Geometory Library {{{ ///
using Point = complex<double>;
#define X real()
#define Y imag()
#define dot(a, b) real(conj(a)*b)
#define cross(a, b) imag(conj(a)*b)
#define norm abs

// +1 : ccw
// -1 : cw
// +2 : a--b--c
// -2 : b--c--a
//  0 : b--a--c
int ccw(Point a, Point b, Point c) {
  b -= a; c -= a;
  if(cross(b, c) > EPS) return +1;
  if(cross(b, c) < -EPS) return -1;
  if(dot(b, c) < 0) return 0;
  if(norm(b) < norm(c)) return +2;
  return -2;
}

double arg(Point a, Point b) {
  return acos(dot(a, b) / norm(a) / norm(b));
}
/// ---}}} ///

using D = tuple<double, int>;
Point ps[1002];

int sx=ini,sy=ini,tx=ini,ty=ini;
int n=ini;
int r[1002];

inline double dis(int ida, int idb) {
  return max(norm(ps[ida] - ps[idb]) - r[ida] - r[idb], .0);
}

int main() {
  REP(i, n) {
    int x=ini,y=ini;
    r[i]=ini;
    ps[i] = Point(x, y);
  }
  ps[n] = Point(sx, sy);
  ps[n+1] = Point(tx, ty);
  vector<double> dist(n + 2, INF * 4.0);
  priority_queue<D, vector<D>, greater<D>> pq;

  dist[n] = 0;
  pq.push(D(0, n));

  n += 2;

  while(pq.size()) {
    double d = fi(pq.top());
    int i = se(pq.top());
    pq.pop();
    if(dist[i] < d) continue;
    if(i == n-1) break;
    REP(j, n) if(i != j) {
      double nd = d + dis(i, j);
      if(nd < dist[j]) {
        dist[j] = nd;
        pq.push(D(nd, j));
      }
    }
  }

  cout << setprecision(10) << dist[n-1] << endl;
}
