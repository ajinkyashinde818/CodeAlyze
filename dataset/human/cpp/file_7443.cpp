#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int n;
  ll S=0, s=0, ans=(ll)(1e18);
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    S += a[i];
  }
  for (int i = 0; i < n - 1; i++) {
    s += a[i];
    ans = min(ans, abs(S - 2*s));
  }
  cout << ans << endl;
}
