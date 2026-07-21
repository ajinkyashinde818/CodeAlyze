#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector<long long> as(n);
  for (long long &a : as) cin >> a;
  vector<long long> bs(n + 1);
  vector<long long> cs(n + 1);
  bs[0] = 0;
  cs[n] = 0;
  for (int i = 0; i < n; ++i) {
    bs[i + 1] = bs[i] + as[i];
    cs[n - i - 1] = cs[n - i] + as[n - i - 1];
  }

  for (int i = 0; i <= n; ++i) {
    bs[i] = abs(bs[i] - cs[i]);
  }
  bs[0] = -1;
  bs[n] = -1;
  sort(bs.begin(), bs.end());

  cout << bs[2] << endl;
  return 0;
}
