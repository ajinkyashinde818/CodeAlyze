#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  vector<ll> s(n+1, 0);

  for(int i=0; i<n; i++){
    s[i+1] = s[i] + a[i];
  }
  
  
  ll ans = 1001001001001001001;
  for(int i=1; i<n; i++){
    ll x = s[i];
    ll y = s[n]-s[i];
    ans = min(ans, abs(y-x));
  }
  
  cout << ans << endl;

  return 0;
}
