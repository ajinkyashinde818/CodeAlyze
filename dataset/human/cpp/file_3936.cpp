#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <tuple>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vec;
typedef vector<vec> mat;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define revrep(i, n) for(ll i = (n)-1; i >= 0; i--)
#define pb push_back
#define f first
#define s second
/*
ll max(ll a, ll b){return (a > b) ? a : b;}
ll min(ll a, ll b){return (a < b) ? a : b;}
ll max3(ll a, ll b, ll c){return max(a, max(b, c));};
ll min3(ll a, ll b, ll c){return min(a, min(b, c));};
ll max4(ll a, ll b, ll c, ll d){return max(max(a, b), min(c, d));};
ll min4(ll a, ll b, ll c, ll d){return min(min(a, b), min(c, d));};
ll max5(ll a, ll b, ll c, ll d, ll e){return max(max(a, b), max3(c, d, e));};
ll min5(ll a, ll b, ll c, ll d, ll e){return min(min(a, b), min3(c, d, e));};
*/
const ll INFL = 1LL << 60;//10^18 = 2^60
const int INF = 1 << 30;//10^9
//ll MOD = 1000000007;
ll MOD = 998244353;

vector<ll> dy = {0, 0, 1, -1, 1, 1, -1, -1, 0};
vector<ll> dx = {1, -1, 0, 0, 1, -1, 1, -1, 0};


ll pow_long(ll x, ll k){
  ll res = 1;
  while(k > 0){
    if(k % 2) res *= x;
    x *= x;
    k /= 2;
  }
  return res;
}
ll pow_mod(ll x, ll k){
  ll res = 1;
  while(k > 0){
    if(k % 2){
      res *= x; res %= MOD;
    }
    x *= x; x %= MOD;
    k /= 2;
  }
  return res;
}

ll inverse(ll x){return pow_mod(x, MOD - 2);};

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll x, ll y){return x / gcd(x, y) * y;};

ll kai_mod(ll x){
  if(x == 0) return 1;
  return x * kai_mod(x-1) % MOD;
}

/*
//コンビネーション
const int MAXcomb = 200010;
ll fac[MAXcomb], finv[MAXcomb], inv[MAXcomb];
//facはn!,finvは1/n!
//invは逆元
void COMinit(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAXcomb; i++){
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}
ll comb(int n, int k){
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fac[n] * finv[k] % MOD * finv[n-k] % MOD;
}
*/

double xs, ys, xt, yt;
ll N;
const ll size = 1010;
double x[size], y[size], r[size];

double distance(ll i, ll j){
  double delta = pow(x[i] - x[j], 2.) + pow(y[i] - y[j], 2.);
  delta = pow(delta, 0.5);
  return max(0., delta - r[i] - r[j]);
}

typedef pair<double, ll> P;

double dist[size];

double dijkstra(){
  priority_queue<P, vector<P>, greater<P>> pque;
  pque.push({0, N});
  rep(i, N) dist[i] = 1. * INFL;
  dist[N] = 0.;
  dist[N+1] = 1. * INFL;
  while(!pque.empty()){
    P p = pque.top();
    pque.pop();
    if(dist[p.s] < p.f) continue;
    if(p.s == N + 1){
      return p.f;
    }
    for(ll i = 0; i < N + 2; i++){
      if(p.s == i) continue;
      double delta = distance(p.s, i);
      if(dist[p.s] + delta < dist[i]){
        dist[i] = dist[p.s] + delta;
        pque.push({dist[i], i});
      }
    }
  }
  return 1. * INFL;
}


int main(){
  cin >> xs >> ys >> xt >> yt;
  cin >> N;
  rep(i, N) cin >> x[i] >> y[i] >> r[i];
  x[N] = xs, y[N] = ys, r[N] = 0.;
  x[N+1] = xt, y[N+1] = yt, r[N+1] = 0.;
  cout << fixed << setprecision(10) << dijkstra() << endl;
}
