#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef long double ld;
typedef vector<ld> vd;
typedef bool bl;
typedef vector<bl> vb;
typedef unordered_map<ll,unordered_map<ll,ll>> graph;

const ll e5 = 1 << 20;
const ll mod = 1000000007;
const ll e3 = 1 << 13;
const ll INF = 1ll << 60;

ll r,g,b,n;
ll ans;

int main(){
  cin >> r >> g >> b >> n;
  for(ll i = 0;i <= 3000;i++){
    for(ll j = 0;j <= 3000;j++){
      if((n-i*r-j*g)%b == 0 && (n-i*r-j*g) >= 0) ans++;
    }
  }
  cout << ans << endl;
}
