//c++ -std=gnu++14 a.cpp
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
#include <fstream>
#include <random>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
//typedef pair<ll, ll> P;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define revrep(i, n) for(int i = (n)-1; i >= 0; i--)
#define pb push_back
#define f first
#define s second
#define chmin(x, y) x = min(x, y);
#define chmax(x, y) x = max(x, y);
#define len(x) ((int)(x).size())

//const ll INFL = LLONG_MAX;//10^18 = 2^60
const ll INFL = 1LL<<60;
//const int INF = INT_MAX;
const int INF = 1 << 30;//10^9
const ll MOD = 1000000007;
//const ll MOD = 998244353;
double EPS = 1e-10;

vector<ll> dy = {0, 1, 0, -1, 1, 1, -1, -1, 0};
vector<ll> dx = {1, 0, -1, 0, 1, -1, 1, -1, 0};

void pres(double A){printf("%.9lf\n", A);}
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

ll lcm(ll x, ll y){
  ll res = x / gcd(x, y);
  res *= y;
  return res;
};


//コンビネーション
const int MAXcomb = 2000010;
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


ll disit(ll s, ll base = 10){
  ll res = 0;
  while(s){
    res++;
    s /= base;
  }
  return res;
}

ll N;
vector<ll> A, B;
ll cntA[200010];
ll cntB[200010];
void solve(){
  cin >> N;
  A.resize(N), B.resize(N);
  rep(i, N) cin >> A[i];
  rep(i, N) cin >> B[i];
  rep(i, N){
    cntA[A[i]]++;
    cntB[B[i]]++;
  }
  vector<pair<pair<ll, ll>, pair<ll, ll>>> num;
  ll M = 0;
  rep(i, 200010){
    if(cntA[i] != 0 || cntB[i] != 0){
      num.pb({{cntA[i] + cntB[i], i}, {cntA[i], cntB[i]}});
      M = max(M, cntA[i] + cntB[i]);
    }
  }
  if(M > N){
    cout << "No" << endl;
    return;
  }
  sort(num.begin(), num.end());
  reverse(num.begin(), num.end());
  ll b = 0;
  ll c = 0;
  ll d = N;
  vector<pair<ll, ll>> pA;
  queue<ll> tB, tC;
  rep(i, len(num)){
    if(d >= num[i].s.f + num[i].s.s){
      d -= num[i].s.f + num[i].s.s;
      rep(_, num[i].s.f){
        tB.push(num[i].f.s);
      }
      rep(_, num[i].s.s){
        tC.push(num[i].f.s);
      }
    }else{
      while(d != 0 && num[i].s.f != 0){
        num[i].s.f--;
        d--;
        tB.push(num[i].f.s);
      }
      while(d != 0 && num[i].s.s != 0){
        num[i].s.s--;
        d--;
        tC.push(num[i].f.s);
      }
      int cntLoop = 0;
      while(num[i].s.f != 0){
        cntLoop++;
        if(cntLoop > 200010){
          cout << "No" << endl;
          return;
        }
        int s = len(tC);
        if(s == 0) continue;
        int x = tC.front();
        tC.pop();
        pA.pb({num[i].f.s, x});
        num[i].s.f--;
      }
      cntLoop = 0;
      while(num[i].s.s != 0){
        cntLoop++;
        if(cntLoop > 200010){
          cout << "No" << endl;
          return;
        }
        int s = len(tB);
        if(s == 0) continue;
        int x = tB.front();
        tB.pop();
        pA.pb({x, num[i].f.s});
        num[i].s.s--;
      }
    }
  }
  sort(pA.begin(), pA.end());
  cout << "Yes" << endl;
  rep(i, N){
    cout << pA[i].s << endl;
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}
