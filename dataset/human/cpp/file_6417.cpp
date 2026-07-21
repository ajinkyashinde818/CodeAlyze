#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef long double ld;
typedef vector<ld> vd;
typedef bool bl;
typedef vector<bl> vb;
typedef vector<vl> mt;
typedef unordered_map<ll,unordered_map<ll,ll>> graph;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef vector<string> vs;
typedef vector<vs> table;
typedef vector<vl> v2;
typedef vector<v2> v3;
typedef vector<v3> v4;


const ll e5 = 1 << 20;
const ll mod = 1000000007;
const ll e3 = 1 << 13;
const ll INF = 1ll << 50;

ll n;
string s;
vl a;
ll x;
void error(){
  cout << 0 << endl;
  exit(0);
}
ll factorial(ll n,ll mod = mod){
  ll ret = 1;
  for(ll i = 1;i <= n;i++){
    ret *= i;
    ret %= mod;
  }
  return ret;
}

ll ans = 1;

int main(){
  cin >> n;
  cin >> s;
  a = vl(2*n);
  for(ll i = 0;i < 2*n;i++){
    ll d;
    if(((x+1000000)%2 == 0 && s[i] == 'B') || ((x+1000000)%2 == 1 && s[i] == 'W')) d = 1;
    else d = -1;
    a[i] = d;
    x += d;

  }
  if(x != 0) error();
  ll mem = 0;
  for(ll i = 0;i < 2*n;i++){
    if(a[i] == 1) mem++;
    else{
      ans *= mem;
      ans %= mod;
      mem--;
    }
  }
  ans *= factorial(n);
  ans %= mod;
  cout << ans << endl;


}
