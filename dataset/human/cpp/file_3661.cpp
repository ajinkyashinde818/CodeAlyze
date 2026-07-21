#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <iostream>
#include <cstdio>
#include <set>
#include <complex>
#include <fstream>

const double PI = acos(-1);
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
const ll MOD=ll(1e9+7);
const ll INF = ll(1e18) + 7;
 
//repetition
#define REP(i,n)  for(ll i=0;i<n;i++)
#define RREP(i,n)  for(ll i=n;i != 0;i--)
 
ll gcd(ll a,ll b)
{
	if (a%b==0)
	{
		return(b);
    }
	else
	{
		return(gcd(b,a%b));
    }
}

unsigned getDigit(unsigned num){
    unsigned digit=0;
    while(num!=0){
        num /= 10;
        digit++;
    }
    return digit;
}
 
unsigned binarySearch(ll target, ll max, ll min) {
  while((max - min) > 1) {
      if((max + min)/2 > target) {
        max = (max + min)/2;
        min = min;
      } else {
        max = max;
        min = (max + min)/2;
      }
    }
}
 
void f(int rest, string s) {
  char abc[] = "abc";
  if(rest == 0) {
    cout << s << endl;
  } else {
    for(int i=0; i < 3; i++) {
      f(rest - 1, s+abc[i]);
    }
  }
} 
 
 
 
// origin (ox, oy) destination (dx, dy)
//
/*
ll dfs2(ll ox, ll oy, vector<vector<char>> v, vector<vector<int>> dist) {
 
  int m = 0;
  for (int i = 0; i < 4; i++) {
    int nx = ox+dx[i], ny = oy + dy[i];
    if(nx < 0 || nx >= w || ny < 0 || nx >= h) continue;
    if(v[nx][ny] != '.') continue;
 
    if(dist[nx][ny] == -1) {
      dist[nx][ny] = dist[ox][oy] + 1;
 
      dist[nx][ny] = min(dist[ox][oy], dist[nx][ny]);
 
      cout << "v[nx][ny]: " << dist[nx][ny] << endl;
      cout << "dx: " << dx << endl;
      cout << "dy: " << dy << endl;
      cout << "v[ox][oy]: " << v[ox][oy] << endl;
      cout << "(nx, ny)" << "("<< nx << "," << ny << ")"<< endl;
      dfs2(nx, ny, v, dist);
    }
    m = max(m, dist[nx][ny]);
  }
  return m;
}
 
int main() {
  // n,m->size, k-> value
  // vector<vector<ll>> a(n ,vector<ll>(m, k));
  // vector
  // vector<ll> s(n,0);
  // vector<vector<ll>> v;
  // map<ll,ll> m;
  // priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  // vector<pair<ll, ll>> epv(n, {0, 0});
  // vector<vector<char>> v(h, vector<char>(w));
  
  for(auto&& m: em) {
    epv.push_back({ m.second, m.first });
  }
 
  ll n, k, a;
  cin >> n >> k;
 
  vector<ll> vp;
  vector<ll> vn;
 
  ll c = 0;
 
  REP(i, n) {
    cin >> a;
    if(a >= 0 ) vp.push_back(a);
    else vn.push_back(a);
  }
 
  sort(vp.begin(), vp.end());
  sort(vn.begin(), vn.end());
 
  ll ps = vp.size();
  ll ns = vn.size();
 
  cout << "k: " << k << endl;
  cout << "ps: " << ps << endl;
  cout << "ns: " << ns << endl;
 
  if(k < ps * ns) {
    ll m = k%ns;
    ll d = k - (m+1);
    cout << vn[m] * vp[d] << endl;
 
  }else {
    ll kd = k - ps*ns;
    ll md = kd%ps;
    ll dd = kd - md;
 
 
    ll s = 0;
    REP(i, ps) {
      s = s+(ps-i-1);
      cout << "s: " << s << endl;
      cout << "kd: " << kd << endl;
      cout << "s: " << s << endl;
      cout << "kd: " << kd << endl;
      cout << "i: " << i << endl;
      if(s > kd) {
        cout << "vp[i]: " << vp[i] << endl;
        cout << "vp[ps-i]: " << vp[s-kd+i-1] << endl;
        cout << vp[i] * vp[s-kd+i-1] << endl;
        break;
      }
    }
  }
 
}
 
 
ll h, w;
vector<vector<char>> v;
 
vector<ll> dx = {-1, 0, 1, 0};
vector<ll> dy = {0, -1, 0, 1};
 
ll bfs(ll ox, ll oy) {
  vector<vector<ll>> vd(h, vector<ll>(w, -1));
  queue<pair<ll, ll>> q;
  q.push({ox, oy});
  vd[oy][ox] = 0;
 
  ll res = 0;
  while(!q.empty()) {
    pair<ll, ll> vn = q.front();
    q.pop();
    res = max(res, vd[vn.second][vn.first]);
 
    for(ll i = 0; i < 4; i++){
      ll nx = vn.first +dx[i];
      ll ny = vn.second + dy[i];
 
      if(nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
      if(v[ny][nx] == '#') continue;
      if(vd[ny][nx] == -1) {
        vd[ny][nx] = res + 1;
        q.push({nx, ny});
      }
    }
  }
  return res;
}
 
bool kai(string s) {
   bool flg = true;
   ll n = s.size();
   for(ll i=0; i<n/2; i++) {
     if(s[i] == s[n-1 -i]){
       flg = true;
     } else {
       flg = false;
       break;
     }
   }
 
   return flg;
}
*/

struct UnionFind {
  vector<ll> par;
  map<ll, ll> s;

  UnionFind(ll n) : par(n) {
    REP(i, n) {
      par[i] = i;
      s[i]++;
    }
  }

  ll root(ll x) {
    if(par[x] == x) return x;
    return root(par[x]);
  }

  void unite(ll x, ll y) {
    ll rx = root(x);
    ll ry = root(y);
    if(rx == ry) return;

    if(size(rx) > size(ry)) {
      s[rx] = s[rx] + s[ry];
      par[root(y)] = rx;
    } else {
      s[ry] = s[ry] + s[rx];
      par[root(x)] = ry;
    }
  }

  bool same(ll x , ll y) {
    return root(x) == root(y);
  }

  ll size(ll x) {
    return s[root(x)];
  }
};
 
ll mod_pow(ll base, ll exp, ll mod) {
  if(exp == 1) return base%mod;
  if(exp%2 == 1) return (base*mod_pow(base, exp-1, mod))%mod;
  ll t = mod_pow(base, exp/2, mod);
  return (t*t)%mod;
}

// nPr
ll mod_permutation(ll n, ll r) {
  ll t = 1;
  while(r != 0){
    t = (t%MOD) * (n%MOD);
    n--;
    r--;
  }
  return t;
}

ll mod_factorial(ll r) {
  ll v = 1;
  while(r != 0){
    v= (v%MOD) * (r%MOD);
    r--;
  }
  return v;
}

deque<ll> prime_factorization(ll n) {
  vector<ll> P;
  ll nn = sqrt(n)+2;
  vector<ll> prime(nn, true);

  for(ll i = 2; i <= nn; i++ ){
      if(prime[i]){
          for(ll j = 2 * i; j <= nn; j += i ){
              prime[j] = false;
          }
          P.emplace_back(i);
      }
  }

  deque<ll> d;
  REP(i, P.size()) {
    while(n%P[i] == 0) {
      d.push_back(P[i]);
      n/=P[i];
    }
  }
  if(n > nn) d.push_back(n);
  return d;
}

struct Node {
  vector<ll> edges;
  vector<ll> costs;
  bool done;
  ll cost;

  friend bool operator<(const Node& lhs, const Node& rhs){ return rhs.cost < lhs.cost; }
};

ll mod_conb() {
  //((p%MOD)*(mod_pow(k, MOD-2)%MOD)*(mod_pow(ki, MOD-2)%MOD))%MOD
}


vector<vector<ll>> vv;
ll c = 0;
vector<ll> v;

ll n,m,q;
// indexからmまでのn桁の数列の列挙
void dfs2(ll index, ll count) {
  if(count < n) {
    for(ll i= index; i <= m; i++) {
      v[count] = i;
      dfs2(i, count+1);
    }
  } else {
    vv.push_back(v);
  }
}

ll total(vector<ll> v) {
  ll t = 0;
  REP(i, v.size()) {
    t+=v[i];
  }
  return t;
}

int main() {
  ll n;
  // std::ifstream in("testcase_17");
  // std::cin.rdbuf(in.rdbuf());
  cin >> n;
  vector<ll> v;

  ll a;
  REP(i ,n) {
    cin >> a;
    v.push_back(a);
  }

  sort(v.begin(), v.end());

  REP(i, n) {
    if(i < n-1) {
      if(v[i] + v[i+1] < 0) {
        v[i] = -v[i];
        v[i+1] = -v[i+1];
      }
    }
  }

  cout << total(v) << endl;
}
