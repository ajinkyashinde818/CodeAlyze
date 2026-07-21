#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  int n; cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];

  ll cs[n];
  cs[0] = a[0];
  for (int i = 1; i < n; i++) cs[i] = cs[i-1] + a[i];
  
  ll ans = abs(cs[0] * 2 - cs[n-1]);
  for (int i = 1; i < n-1; i++) {
    ans = min(ans, abs(cs[i] * 2 - cs[n-1]));
  }
  cout << ans << endl;
}
