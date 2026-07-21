#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<int64_t> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] += a[i - 1];
  }

  int64_t ans = abs(2 * a[1] - a[n]);
  for (int i = 1; i < n - 1; ++i) {
    ans = min(ans, abs(2 * a[i] - a[n]));
  }
  cout << ans << "\n";
}
