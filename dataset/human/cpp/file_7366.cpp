#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  for(int i=0;i<n;i++) cin >> a[i];

  ll sum = 0;
  for(int i=0;i<n;i++) sum += a[i];

  ll x = a[0];
  ll ans = abs(sum-x-x);
  for(int i=1;i<n-1;i++){
    x += a[i];
    ll y = sum - x;
    ans = min(ans,abs(x-y));
  }

  cout << ans << endl;
}
