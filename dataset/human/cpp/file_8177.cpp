#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
  ll n, s=0;
  cin >> n;
  ll a[n];
  for(int i=0; i<n; i++){
    cin >> a[i];
    s += a[i];
  }
  ll x=0, ans = 1000000000000000;
  for(int i=0; i<n-1; i++){
    x += a[i];
    ans = min(ans, abs(s-2*x));
  }
  cout << ans << endl;
  return 0;
}
