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
constexpr long long int NINF = std::numeric_limits<long long int>::min();
#define int long long int

void solve() {
  int N;
  cin >> N;

  vector<int> v(N);
  int sum = 0;
  for (int &a : v) {
    cin >> a;
    sum += a;
    a = sum;
  }

  int ans = INF;
  for (int i = 0; i < N - 1; i++) {
    ans = min(ans, abs(sum - v[i] - v[i]));
  }
  cout << ans << endl;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
