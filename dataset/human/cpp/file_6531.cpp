#include <bits/stdc++.h>
#include <boost/algorithm/string/join.hpp>
#include <boost/range/irange.hpp>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::irange;
using boost::algorithm::join;

typedef long long ll;
typedef unsigned long long ull;
//typedef long double ld;

typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<double,double> pdd;
typedef set<int> si;
typedef set<ll> sll;
typedef vector<int> vi;
typedef vector<pair<int, int > > vii;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vll> vvll;

constexpr ll MOD = 1e9+7;
template<typename T>constexpr auto inf=numeric_limits<T>::max()/4;
constexpr int INF=inf<int>;
constexpr ll LINF=inf<ll>;

#define Sort(x) sort(begin(x),end(x))
#define Reverse(x) reverse(begin(x),end(x))
#define ABS(a,b) ((a)<(b)?(b)-(a):(a)-(b))
#define nbit(n) (1ull<<(n))
#define _ol3(_1,_2,_3,name,...)name
#define _rep(i,n)_repi(i,0,n)
#define _repi(i,a,b)for(int i=a,i##_l=(b);i<i##_l;++i)
#define REP(...) _ol3(__VA_ARGS__,_repi,_rep,)(__VA_ARGS__)
#define REPR(i,n) for(int i=n-1;i>=0;--i)
#define REPA(i,v) REP(i,(v).size())

// sort(begin(x), end(x), greater<ll>());
// lower_bound(a.begin(), a.end(), val): a[i] ≥ valである最左の位置
// upper_bound(a.begin(), a.end(), val): a[i] > valである最左の位置

// Returns minimum of a and b.
// If a is less b, a is set to b.
template<typename T>
T chmin(T& a, T b) {
  if (a > b) {
    a = b;
  }
  return a;
}

// Returns maximum of a and b.
// If a is less b, a is set to b.
template<typename T>
T chmax(T& a, T b) {
  if (a < b) {
    a = b;
  }
  return a;
}

template <typename T>
void dumpContents(const T& v, const string& msg)
{
  cerr << "### " << msg << " ###\n";
  for (const auto& x : v) {
    cerr << x << " ";
  }
  cerr << endl;
}

struct before_main_function {
  before_main_function() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<setprecision(20)<<fixed;
    #define endl "\n"
  }
} before_main_function;

struct mint {
  ll x;

  mint(ll _x=0) : x(_x%MOD) {}

  mint& operator+=(const mint a) {
    if ((x += a.x) >= MOD) x -= MOD;
    return *this;
  }

  mint& operator-=(const mint a) {
    if ((x += MOD-a.x) >= MOD) x -= MOD;
    return *this;
  }

  mint& operator*=(const mint a) {
    (x *= a.x) %= MOD;
    return *this;
  }

  mint operator+=(const mint a) const {
    mint ret(*this);
    return ret+=a;
  }

  mint operator-=(const mint a) const {
    mint ret(*this);
    return ret-=a;
  }

  mint operator*=(const mint a) const {
    mint ret(*this);
    return ret*=a;
  }

  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }

  mint operator+(const mint a) const {
    mint ret(*this);
    return ret += a;
  }

  mint operator-(const mint a) const {
    mint ret(*this);
    return ret -= a;
  }

  mint operator*(const mint a) const {
    mint ret(*this);
    return ret *= a;
  }
  mint operator/(const mint a) const {
    mint ret(*this);
    return ret/=a;
  }

  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  mint inv() const {
    // MOD should be a prime
    return pow(MOD-2);
  }

};

ostream& operator<<(ostream& os, const mint& a) {
    os << a.x;
    return os;
}
// ========== end of template ==========
int N;
string S;

int main(int argc, char** argv) {
  cin >> N;
  cin >> S;

  if (S[0] != 'B' || S[2*N-1] != 'B') {
    cout << 0 << endl;
    return 0;
  }

  mint ret = 1;
  int open = 0;
  for (auto c : S) {
    int flip = open + (c=='B' ? 1 : 0);
    flip %= 2;
    if (flip) {
      open++;
    } else {
      ret *= open;
      open--;
      if (open<0) {
        cout << 0 << endl;
        return 0;
      }
    }
  }
  if (open) {
    cout << 0 << endl;
    return 0;
  }

  for (int i=1; i<=N; i++) {
    ret *= i;
  }

  cout << ret << endl;
  return 0;
}
