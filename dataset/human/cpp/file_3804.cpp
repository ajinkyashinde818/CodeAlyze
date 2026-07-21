#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, double> p_ld;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
#define repr(i,from,to) for (ll i=(ll)from; i<(ll)to; i++)
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

struct barrier { double x, y, r; };

// ----------------------------------------------------------------------
// ----------------------------------------------------------------------

struct edge { ll to; double d; };
vector<vector<edge>> adj;

vector<double> dijkstra(int n=0) {
  int N = adj.size();
  auto c = [](const p_ld &x, const p_ld &y){return x.second>y.second;};
  priority_queue<p_ld, vector<p_ld>, decltype(c)> q(c);
  vector<double> result(N,LLINF); result[n] = 0; q.push(make_pair(n,0));
  while(q.size()) {
    p_ld now = q.top(); q.pop();
    ll np = now.first; double nd = now.second;
    if (nd>result[np]) continue;
    for (auto x: adj[np]) {
      if (result[x.to]<=result[np]+x.d) continue;
      q.push(make_pair(x.to, result[np]+x.d));
      result[x.to] = result[np]+x.d;
    }
  }
  return result;
}

// ----------------------------------------------------------------------
// ----------------------------------------------------------------------

int main() {
  double xs, ys, xt, yt; cin >> xs >> ys >> xt >> yt;
  ll N; cin >> N;
  barrier b[N+2]; rep(i,N) cin >> b[i+1].x >> b[i+1].y >> b[i+1].r;
  b[0] = {xs,ys,0}; b[N+1] = {xt,yt,0};

  adj.resize(N+2);
  rep(i,N+2) rep(j,N+2) {
    if (i==j) continue;
    double l = max((double)0, sqrt(pow(b[i].x-b[j].x,2)+pow(b[i].y-b[j].y,2))-(b[i].r+b[j].r));
    adj[i].push_back({j,l});
  }
  vector<double> d = dijkstra();

  double result = d[N+1];
  cout << setprecision(10) << result << endl;
  return 0;
}
