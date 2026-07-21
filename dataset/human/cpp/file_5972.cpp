#include <algorithm>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;

const ll solve(const ll C, const vector<ll>& x, const vector<ll>& v) {
  const int N = x.size();
  vector<ll> dp(N + 1);
  ll acc = 0, pre = 0;
  for (int i = 0; i < N; i++) {
    acc += v[i] - (x[i] - pre);
    pre = x[i];
    dp[i + 1] = max(dp[i], acc);
  }
  ll res = *max_element(dp.begin(), dp.end());
  acc = 0, pre = C;
  for (int i = N - 1; i >= 0; i--) {
    acc += v[i] - (pre - x[i]);
    pre = x[i];
    res = max(res, acc - (C - x[i]) + dp[i]);
  }
  return res;
}

int main() {
  int N;
  ll C;
  while (cin >> N >> C) {
    vector<ll> x(N), v(N);
    for (int i = 0; i < N; i++) {
      cin >> x[i] >> v[i];
    }
    ll res = 0;
    res = max(res, solve(C, x, v));
    reverse(x.begin(), x.end());
    reverse(v.begin(), v.end());
    for (auto& y : x) {
      y = C - y;
    }
    res = max(res, solve(C, x, v));
    cout << res << endl;
  }
  return 0;
}
