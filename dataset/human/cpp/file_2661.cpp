#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int oo = 1e9 + 7;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, pos = 0, neg = 0, mz = oo;
  ll ans = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int a;
    cin >> a;
    if (a >= 0) pos++;
    else neg++;
    ans += abs(a);
    mz = min(mz, abs(a));
  }
  if (neg % 2 == 0) cout << ans;
  else cout << ans - 2 * mz;
  return 0;
}
