#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
  int n;
  cin >> n;
  if (n == 2){
    ll x, y;
    cin >> x >> y;
    cout << abs(x-y) << endl;
    return 0;
  }
  ll a[n], ansy=0;
  for(int i=0;i<n;i++){
    cin >> a[i];
    ansy+=a[i];
  }
  ansy -= a[0];
  ll ansx=a[0], ans = abs(ansx-ansy); 
  for(int i=1;i<n-1;i++){
    ansx += a[i];
    ansy -= a[i];
    ans = min(ans, abs(ansx-ansy));
  }
  cout << ans << endl;
  return 0;
}
