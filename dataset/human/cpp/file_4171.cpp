#include <bits/stdc++.h>
using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//typedef
//------------------------------------------
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<string> VS;
typedef vector<VS> VVS;
typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef priority_queue<int> PQGI; //大きい順
typedef priority_queue<int, VI, greater<int>> PQLI;
typedef priority_queue<PII> PQGP;
typedef priority_queue<PII, VPII, greater<int>> PQLP;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define EB emplace_back
#define EF emplace_front
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) ((a)*(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define SORTR(c) sort((c).rbegin(), (c).rend())
#define LB lower_bound
#define UB upper_bound
#define NEXP next_permutation
#define FI first
#define SE second
#define Vmin(a) *min_element((a).begin(),(a).end())
#define Vmax(a) *max_element((a).begin(),(a).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define FORR(i,a,b) for(int i = (b-1);i>=(a);i--)
#define REPR(i,n) FORR(i,0,n)
#define CFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define CREP(i,n)  CFOR(i,0,n)
#define CFORR(i,a,b) for(int i = (b);i>=(a);i--)
#define CREPR(i,n) CFORR(i,0,n)
#define BFOR(bit,a,b) for(int bit = (a); bit < (1<<(b)); ++bit)
#define BREP(bit,n) BFOR(bit,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int INF = INT_MAX/2;
const LL LINF = LLONG_MAX/3;
const int RINF = INT_MIN/2;
const LL RLINF = LLONG_MIN/3;
const LL MOD = 1e9+7;
const LL MODD = 998244353;
const int MAX = 510000;

inline bool Eq(double a, double b) { return fabs(b - a) < EPS; }

//other
//-------------------------------------------
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#define COUT(x) cout << (x) << endl
#define COUT2(x,y) cout << (x) << " " << (y) << endl
#define COUT3(x,y,z) cout << (x) << " " << (y) << " " << (z) << endl
#define PR(x) cout << (x)
#define ENDL cout << endl
#define SPACE cout << " "
#define BC(x) __builtin_popcountll(x)

VI dx = {1,0,-1,0,1,1,-1,-1};
VI dy = {0,1,0,-1,1,-1,1,-1};

LL Gcd(LL a, LL b) {return __gcd(a,b);}
LL Lcm(LL a, LL b) {return a/Gcd(a,b)*b;}

LL ModPow(LL A, LL N, LL M){
  LL res = 1;
  while(N>0){
    if(N&1) res = res * A % M;
    A = A * A % M;
    N >>= 1;
  }
  return res;
}

template< typename T1, typename T2 >
istream &operator>>(istream &is, pair< T1, T2 > &p) {
  is >> p.first >> p.second;
  return is;
}

template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
  os << p.first << " " << p.second;
  return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
  for(T &in : v) is >> in;
  return is;
}

template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
  for(int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}

template<typename T>
vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v(ts...))>(a,make_v(ts...));
}

template<class T> struct Point{
  T x,y;
  Point(){}
  Point(T x, T y) : x(x), y(y) {}
  
  Point operator+(const Point &b) const { return Point(x + b.x, y + b.y); }
  Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
  Point operator*(const T b) const { return Point(x * b, y * b); }
  Point operator/(const T b) const { return Point(x / b, y / b); }
  bool operator==(const Point &b) const { return Eq(x, b.x) && Eq(y, b.y); }
  bool operator<(const Point &b) const { 
    if(x==b.x) return y<b.y;
    return x<b.x; }
  T Norm() { return x * x + y * y; }
  double Abs() { return sqrt(Norm()); }
  
  int ort() const {
    if (abs(x) < EPS && abs(y) < EPS) return 0;
    if(y==0) return x>0 ? 1 : 3;
    if(x==0) return y>0 ? 2 : 4;
    if (y > 0) return x>0 ? 1 : 2;
    else return x>0 ? 4 : 3;
  }
  Point rotate90() const { return Point(-y, x);}
  Point rotate180() const { return Point(-x, -y);}
  Point rotate270() const { return Point(y, -x);}

  Point operator*(const Point &b) const { return Point(x*b.x-y*b.y,x*b.y+y*b.x); }
  Point operator/(const Point &b) const { return Point(x*b.x+y*b.y,y*b.x-x*b.y)/(b.x*b.x+b.y*b.y); }
};
template<class T> double Distance(const Point<T> &a, const Point<T> &b) { return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)); }

template<class T> T Cross(const Point<T> &a, const Point<T> &b) { return a.x * b.y - a.y * b.x; }

template<class T> T Dot(const Point<T> &a, const Point<T> &b) { return a.x * b.x + a.y * b.y; }

template<class T> bool Intersect(const Point<T> &a, const Point<T> &b, const Point<T> &c, const Point<T> &d) {
  if( Cross((c-a),(b-a))>0 != Cross((d-a),(b-a))>0 ){
    if( Cross((a-c),(d-c))>0 != Cross((b-c),(d-c))>0 ){
      return true;
    }
  }
  return false;
}
typedef Point<LL> point;
typedef vector<point> polygon;

using PD = pair<int, double>;

int main() {

  // cin.tie(0);
  // ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  //ifstream in("input.txt");
  //cin.rdbuf(in.rdbuf());

  LL sx,sy,tx,ty;
  cin >> sx >> sy >> tx >> ty;
  int N; cin >> N;

  //cout << sx << sy << tx << ty;

  polygon pol(N+2);

  VD r(N+2,0);

  pol.at(0) = {sx,sy};
  pol.at(1) = {tx,ty};

  REP(i,N){
    int j = i+2;
    LL x,y;
    double l;
    cin >> x >> y >> l;
    pol.at(j).x = x;
    pol.at(j).y = y;
    r.at(j) = l;
  }

  VVD dist(N+2,VD(N+2,0));

  REP(i,N+2)REP(j,N+2){
    dist.at(i).at(j) = Distance(pol.at(i),pol.at(j)) - r.at(i) - r.at(j);
    chmax(dist.at(i).at(j), 0.0);
  }

  VB seen(N+2,false);
  VD sdist(N+2,LINF);

  auto f = [](PD &a, PD &b){ return a.SE>b.SE;};

  priority_queue<PD,vector<PD>,decltype(f)> pq{f};

  pq.emplace(0,0);

  while(!pq.empty()){
    PD t = pq.top(); pq.pop();
    if(seen.at(t.FI)) continue;
    seen.at(t.FI) = true; sdist.at(t.FI) = t.SE;
    REP(i,N+2){
      if(seen.at(i)) continue;
      double d = t.SE + dist.at(t.FI).at(i);
      if(d >= sdist.at(i)) continue;
      pq.emplace(i,d);
    }
  }

  double ans = sdist.at(1);

  COUT(ans);


  return 0;
}
