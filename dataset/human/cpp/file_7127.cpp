#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll n;
  cin >> n;
  ll sum[n + 1] = {};
  for(ll i = 0; i < n; i++){
    ll a;
    cin >> a;
    sum[i + 1] = sum[i] + a;
  }
  ll ans = 1145148931919810;
  for(ll i = 1; i < n; i++) ans = min(ans, (ll)abs(sum[i] - (sum[n] - sum[i])));
  cout << ans << endl;
  return 0;
}
