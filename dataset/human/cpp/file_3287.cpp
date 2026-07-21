#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

// clang-format off
template <typename T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
template <typename T> T lcm(T a, T b) { return a * b / gcd(a, b); }
template <typename T> T clamp(T val, T min, T max) { return val < min ? min : (max < val ? max : val); }
template <typename T> size_t max_index(T begin, T end) { return distance(begin, max_element(begin, end)); }
template <typename T> size_t min_index(T begin, T end) { return distance(begin, min_element(begin, end)); }
// clang-format on

#define int long long
#define YES "Yes"
#define NO  "No"

using namespace std;

signed main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int num;

  int n; cin >> n;
  int m = 0;
  vector<int> a(n);
  for (auto it = a.begin(); it != a.end(); ++it) {
    cin >> *it;
    if (*it <= 0) ++m;
  }

  num = 0;
  if (m % 2 == 0) {
    for (int i = 0; i < n; ++i) num += abs(a[i]);
  } else {
    int tmp = abs(a[0]); // min abs(a[i])
    for (int i = 0; i < n; ++i) {
      num += abs(a[i]);
      tmp = min(abs(a[i]), tmp);
    }
    num -= 2 * tmp;
  }
  
  cout << num << endl;
  
  return 0;
}
