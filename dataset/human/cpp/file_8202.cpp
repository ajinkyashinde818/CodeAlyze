#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll n; cin >> n;
  vector<ll> a(n);
  ll sum = 0;
  for(int i=0; i<n; ++i){
    cin >> a[i];
    sum += a[i];
  }
  ll x = a[0], y = sum - a[0];
  ll res = abs(x - y);
  for(int i=1; i<n-1; ++i){
    x += a[i]; y -= a[i];
    if(abs(x - y) < res) res = abs(x - y);
  }
  cout << res << endl;
  return 0;
}
