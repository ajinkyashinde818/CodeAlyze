#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N; { cin >> N; }
  ll C; { cin >> C; }
  vector<ll> x(N), v(N); { for (int i = 0; i < N; ++i) cin >> x[i] >> v[i]; }

  vector<ll> dp1(N); {
    dp1[0] = v[0] - x[0];
    for (int i = 1; i < N; ++i) dp1[i] = dp1[i - 1] + v[i] - (x[i] - x[i - 1]);
    for (int i = 1; i < N; ++i) dp1[i] = max(dp1[i], dp1[i - 1]);
  }
  vector<ll> dp2(N); {
    dp2[N - 1] = v[N - 1] - (C - x[N - 1]);
    for (int i = N - 2; i >= 0; --i) dp2[i] = dp2[i + 1] + v[i] - (x[i + 1] - x[i]);
    for (int i = N - 2; i >= 0; --i) dp2[i] = max(dp2[i], dp2[i + 1]);
  }

  ll ans = 0LL; {
    for (int i = 0; i < N; ++i) {
      ll cur = dp1[i];
      if (i + 1 < N && dp2[i + 1] - x[i] > 0) cur += dp2[i + 1] - x[i];
      ans = max(ans, cur);
    }
    for (int i = N - 1; i >= 0; --i) {
      ll cur = dp2[i];
      if (i >= 1 && dp1[i - 1] - (C - x[i]) > 0) cur += dp1[i - 1] - (C - x[i]);
      ans = max(ans, cur);
    }
  }
  cout << ans << endl;
  return 0;
}
