#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;
constexpr long long int INF = std::numeric_limits<long long int>::max();
#define int long long int

void solve() {
  int R, G, B, N;
  cin >> R >> G >> B >> N;

  int ans = 0;
  for (int r = 0; r <= N; r += R) {
    for (int g = 0; g <= (N - r); g += G) {
      if ((N - r - g) % B == 0) {
        ans++;
      }
    }
  }

  cout << ans << endl;
}

signed main() {
  solve();
  return 0;
}
