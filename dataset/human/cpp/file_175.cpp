#include <cmath>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;

constexpr int sz = 3;

vi a(sz);

int n;

void input() {
  for (auto&& i : a)
    cin >> i;

  cin >> n;
}

void solve() {
  // sort(a.rbegin(), a.rend());

  int ans = 0;

  constexpr int bound = 3001;

  for (int i = 0; i < bound; ++i) {
    const int y1 = a[0] * i;

    if (y1 > n)
      break;

    for (int j = 0; j < bound; ++j) {
      const int y2 = a[1] * j;

      if (y1 + y2 > n)
        break;

      if ((n - y1 - y2) % a[2] != 0)
        continue;

      ++ans;
    }
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cout.precision(16);
  cout << fixed;

  int _times = 1;

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  _times = 2;
#endif

  // cin >> _times;

  while (_times--) {
    input();
    solve();
  }
}
