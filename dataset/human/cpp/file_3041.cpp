// Last Change: 04/27/2019 21:58:46.
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

namespace NS {
void LoopUntilZeroInpput() {
  int hogegegege = 0;
  while (cin >> hogegegege && hogegegege != 0) {
  }
}
} // namespace NS

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (auto &&e : A) {
    cin >> e;
  }

  vector<pair<ll, ll>> dp(N); // f:stay, s:reverse;
  dp[N - 2].first = A[N - 1] + A[N - 2];
  dp[N - 2].second = -1 * dp[N - 2].first;

  for (ll i = N - 3; i >= 0; --i) {
    dp[i].first = A[i] + max(dp[i + 1].first, dp[i + 1].second);
    dp[i].second =
        -1 * A[i]
        + max(dp[i + 1].first - 2 * A[i + 1], dp[i + 1].second + 2 * A[i + 1]);
  }

  cout << max(dp[0].first, dp[0].second) << endl;

  //NS::LoopUntilZeroInpput();
}
