#include <bits/stdc++.h>

using namespace std;

int main(){
  using ll = int64_t;
  ll n;
  cin >> n;
  vector<ll> a(n);
  int neg = 0;
  for(auto&& x:a){
    cin >> x;
    if(x < 0){
      neg++;
      x = -x;
    }
  }
  sort(a.begin(),a.end());
  ll ans = accumulate(a.begin(), a.end(), 0LL);
  if(neg&1)ans -= a[0]*2;
  cout << ans << endl;
}
