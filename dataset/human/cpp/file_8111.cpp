#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  lint n, s = 0ll, t, dif = 1e18;
  cin >> n;
  vector<lint> a(n);
  for (auto&& w : a) cin >> w;
  for (auto&& w : a) s += w;
  t = 0ll;
  for (int i = 0; i < n - 1; i++) {
    t += a[i];
    dif = min(dif, abs(s - 2 * t));
  }
  cout << dif << endl;
  
}
