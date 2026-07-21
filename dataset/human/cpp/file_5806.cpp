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
#include <climits>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
//typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define revrep(i, n) for(ll i = (n)-1; i >= 0; i--)
#define pb push_back
#define f first
#define s second
#define chmin(x, y) x = min(x, y);
#define chmax(x, y) x = max(x, y);
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
//const ll INFL = LLONG_MAX;//10^18 = 2^60
const ll INFL = 1LL<<60;
//const int INF = INT_MAX;
const int INF = 1 << 30;//10^9
ll MOD = 1000000007;
//ll MOD = 998244353;

vector<ll> dy = {0, 1, 0, -1, 1, 1, -1, -1, 0};
vector<ll> dx = {1, 0, -1, 0, 1, -1, 1, -1, 0};

void pres(double A, ll x = 10){cout << fixed << setprecision(x) << A << endl;}
void BinarySay(ll x, ll y = 60){rep(i, y) cout << (x>>(y-1-i) & 1); cout << endl;}
ll cnt_bit(ll x){return __builtin_popcountll(x);}

ll pow_long(ll x, ll k){
  ll res = 1;
  while(k > 0){
    if(k % 2) res *= x;
    x *= x; k /= 2;
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

ll N, L;
vector<string> S;
struct node{ll to1 = -1, to2 = -1;};

vector<node> E;




void solve(){
  cin >> N >> L;
  S.resize(N);
  rep(i, N) cin >> S[i];
  node e = {-1, -1};
  vector<ll> depth;
  depth.pb(0);
  E.pb(e);
  ll id = 1;
  rep(i, N){
    ll now = 0;
    rep(j, S[i].size()){
      if(S[i][j] == '0'){
        if(E[now].to1 == -1){
          E[now].to1 = id;
          E.pb(e);
          depth.pb(j+1);
          id++;
        }
        now = E[now].to1;
      }else{
        if(E[now].to2 == -1){
          E[now].to2 = id;
          E.pb(e);
          depth.pb(j+1);
          id++;
        }
        now = E[now].to2;
      }
    }
  }

  ll XOR = 0;
  rep(i, id){
    if(E[i].to1 == -1 && L > depth[i]){
      ll add = 1;
      ll p = L - depth[i];
      while(p % 2 == 0){
        p /= 2;
        add *= 2;
      }
      XOR ^= add;
    }
    if(E[i].to2 == -1 && L > depth[i]){
      ll add = 1;
      ll p = L - depth[i];
      while(p % 2 == 0){
        p /= 2;
        add *= 2;
      }
      XOR ^= add;
    }
  }
  if(XOR){
    cout << "Alice" << endl;
  }else{
    cout << "Bob" << endl;
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}
