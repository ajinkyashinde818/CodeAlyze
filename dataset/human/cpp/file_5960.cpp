/**
 *    author:  tourist
 *    created: 04.01.2020 01:50:49       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  long long c;
  cin >> n >> c;
  vector<long long> x(n);
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> v[i];
  }
  long long ans = 0;
  for (int rot = 0; rot < 2; rot++) {
    long long sum_p = 0;
    for (int i = 0; i < n; i++) {
      sum_p += v[i];
    }
    long long max_s = 0;
    long long sum_s = 0;
    for (int i = n - 1; i >= -1; i--) {
      long long cur = sum_p - (i >= 0 ? x[i] : 0);
      ans = max(ans, cur + max_s);
      if (i >= 0) {
        sum_s += v[i];
        max_s = max(max_s, sum_s - 2 * (c - x[i]));
        sum_p -= v[i];
      }
    }
    for (int i = 0; i < n; i++) {
      x[i] = c - x[i];
    }
    reverse(x.begin(), x.end());
    reverse(v.begin(), v.end());
  }
  cout << ans << '\n';
  return 0;
}
