// Last Change: 08/26/2019 03:57:59.
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
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  vector<ll> a(N);
  ll sumAll = 0;
  for (auto &&e : a) {
    ll ipt;
    cin >> ipt;
    e = sumAll += ipt;
  }

  ll ans = numeric_limits<ll>::max();
  for (ll i = 0; i < N - 1; ++i) {
    ans = min(ans, abs(2 * a[i] - sumAll));
  }
  cout << ans << endl;
}
