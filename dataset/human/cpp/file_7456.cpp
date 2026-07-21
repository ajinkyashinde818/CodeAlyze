#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int64_t s = 0, arai = 0, ans;
  cin >> n;
  vector<int64_t> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
    arai += a.at(i);
  }
  for (int i = 0; i < n - 1; i++) {
    s += a.at(i);
    arai -= a.at(i);
    if (i == 0) {
      ans = abs(s - arai);
    }
    else {
      ans = min(ans, abs(s - arai));
    }
  }
  cout << ans << endl;
}
