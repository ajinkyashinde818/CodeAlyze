#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n = 1e6;
int t[5][5];
ll h,a,b,c,d,e;
int ans = 1;
ll mod = 1e9+7;
bool memo[15][15] = {0};
ll func(ll x){
  ll k = 1;
  while(x>1){
    k *= x;
    k %= mod;
    x--;
  }
  return k;
}
int main(){
  ll m,n;
  cin >> n;
  vector<ll> v(n);
  for(int i=0 ; i<n ; i++){
    cin >> v[i];
  }
  vector<ll> l(n),r(n);
  l[0] = v[0];
  r[n-1] = v[n-1];
  for(int i=1 ; i<n ; i++){
    l[i] = v[i] + l[i-1];
  }
  for(int i=n-2 ; i>=0 ; i--){
    r[i] = v[i]+r[i+1];
  }
  ll mi = 1e17;
  for(int i=0 ; i+1<=n-1 ; i++){
    mi = min(mi, abs(r[i+1]-l[i]));
  }
  if(n==2) mi = abs(v[1]-v[0]);
  cout << mi << endl;
  return 0;
}
