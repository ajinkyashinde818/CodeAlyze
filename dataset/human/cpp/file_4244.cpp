#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> p_ll;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
#define repr(i,from,to) for (int i=(int)from; i<(int)to; i++)
#define all(vec) vec.begin(), vec.end()
#define rep(i,N) repr(i,0,N)
#define per(i,N) for (int i=(int)N-1; i>=0; i--)

const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

vector<ll> fac;
void c_fac(int x=pow(10,6)+10) { fac.resize(x,true); rep(i,x) fac[i] = i ? (fac[i-1]*i)%MOD : 1; }
ll inv(ll a, ll m=MOD) { ll b = m, x = 1, y = 0; while (b!=0) { int d = a/b; a -= b*d; swap(a,b); x -= y*d; swap(x,y); } return (x+m)%m; }
ll nck(ll n, ll k) { return fac[n]*inv(fac[k]*fac[n-k]%MOD)%MOD; }
ll gcd(ll a, ll b) { if (a<b) swap(a,b); return b==0 ? a : gcd(b, a%b); }
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }

// ----------------------------------------------------------------------
// ----------------------------------------------------------------------

struct UnionFind {
  vector<int> par, s, e; 
  UnionFind(int N) : par(N), s(N), e(N) { rep(i,N) { par[i] = i; s[i] = 1; e[i] = 0; } }
  int root(int x) { return par[x]==x ? x : par[x] = root(par[x]); }
  int size(int x) { return par[x]==x ? s[x] : s[x] = size(root(x)); }
  int edge(int x) { return par[x]==x ? e[x] : e[x] = edge(root(x)); }
  void unite(int x, int y) { int rx=root(x), ry=root(y); if (rx!=ry) { s[rx] += s[ry]; e[rx] += e[ry]+1; par[ry] = rx; } else e[rx]++; }
  bool same(int x, int y) {  int rx=root(x), ry=root(y); return rx==ry; }
};

// ----------------------------------------------------------------------
// ----------------------------------------------------------------------

vector<ll> zaatsu(vector<ll> &list) {
  map<ll, ll> num; for (auto x: list) num[x]++;
  ll p = 0; for (auto x: num) { num[x.first] = p; p++; }
  vector<ll> result; for (auto x: list) result.push_back(num[x]);
  return result;
}

// ----------------------------------------------------------------------
// ----------------------------------------------------------------------

int main() {
  int N; cin >> N;
  vector<ll> a(N+1,0); rep(i,N) { cin >> a[i]; a[N] ^= a[i]; }
  vector<ll> b(N+1,0); rep(i,N) { cin >> b[i]; b[N] ^= b[i]; }
  map<ll, ll> ca, cb; rep(i,N+1) { ca[a[i]]++; cb[b[i]]++; }
  bool ok = true; for (auto x: ca) ok &= cb[x.first]==x.second;
  if (!ok) { cout << -1 << endl; return 0; }

  vector<ll> za = zaatsu(a), zb = zaatsu(b);
  // debug(all(za)); debug(all(zb));

  UnionFind uf(N+1);
  rep(i,N+1) if (za[i]!=zb[i]) uf.unite(za[i],zb[i]);
  // rep(i,N+1) cout << i << "->" << uf.root(i) << " " << uf.size(i) << " " << uf.edge(i) << endl;
  ll result = 0;
  rep(i,N) {
    if (i==uf.root(i)) {
      if (i==uf.root(za[N])) {
        if (za[N]==zb[N]) result += uf.edge(i);
        else result += uf.edge(i)-1;
      }
      else if (uf.edge(i)!=0) result += uf.edge(i)+1;
    }
  }
  cout << result << endl;
  return 0;
}
