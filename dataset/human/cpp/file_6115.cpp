#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  long long c;
  cin >> n >> c;
  vector<long long> pos(n);
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> pos[i] >> v[i];
  }

  vector<long long> sum(n + 1), revsum(n + 1);
  for (int i = 0; i < n; i++) {
    sum[i + 1] = sum[i] + v[i];
    revsum[i + 1] = revsum[i] + v[n - 1 - i];
  }

  vector<long long> a1(n + 1), a2(n + 1), b1(n + 1), b2(n + 1);
  for (int i = 0; i < n; i++) {
    a1[i + 1] = max(a1[i], sum[i + 1] - pos[i]);
    a2[i + 1] = max(a2[i], sum[i + 1] - 2 * pos[i]);
    b1[i + 1] = max(b1[i], revsum[i + 1] - (c - pos[n - 1 - i]));
    b2[i + 1] = max(b2[i], revsum[i + 1] - 2 * (c - pos[n - 1 - i]));
  }

  long long ans = max(a1[n], b1[n]);
  for (int i = 0; i <= n; i++) {
    ans = max(ans, a1[i] + b2[n - i]);
    ans = max(ans, a2[i] + b1[n - i]);
  }
  cout << ans << '\n';
  return 0;
}
