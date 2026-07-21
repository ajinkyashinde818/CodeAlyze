#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N; cin >> N;
  ll R; cin >> R;

  ll ans = R;
  if (N < 10) {
    ans += 100 * (10 - N);
  }

  cout << ans << '\n';
  return 0;
}
