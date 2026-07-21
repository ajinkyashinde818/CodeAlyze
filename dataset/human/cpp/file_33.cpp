#include <bits/stdc++.h>

using namespace std;

const int N = 200000 + 7;

typedef long long ll;
int main() {
  ll r, g, b, n;
  cin >> r >> g >> b >> n;
  ll rr = n / r;
  ll gg = n / g;
  ll bb = n / b;
  ll ans = 0;
  for(ll i = 0; i <= rr; ++i) {
    ll cur = r * i;
    if(cur > n) break;
    for(ll j = 0; j <= gg; ++j) {
      ll ncur = cur + g * j;
      if(ncur > n) break;
      ll rem = n - ncur;
      //cout << ncur << rem << rem %b << endl;
      if(rem >= 0 && rem % b == 0) {
        //cout << i << j << rem / b << endl;
        ++ans;
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
