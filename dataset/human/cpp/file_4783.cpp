#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

#define EPS (1e-7)

int main() {
  ll N, R;
  cin >> N >> R;

  ll ans = R;
  if (N < 10) {
    ans = R + 100 * (10 - N);
  }

  cout << ans << endl;
  return 0;
}
