#include <bits/stdc++.h>
using namespace std;

int main () {
  int n;
  cin >> n;
  vector<int> a(n);
  long x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
    x += a.at(i);
  }
  long ans;
  for (int i = n-1; i > 0; i--) {
    x -= a.at(i);
    y += a.at(i);
    if (i == n-1) ans = abs(x-y);
    else ans = min(ans, abs(x-y));
  }
  cout << ans << endl;
}
