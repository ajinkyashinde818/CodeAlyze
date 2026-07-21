#include <algorithm>
#include <cstdint>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int64_t> a(n);
  int64_t sum = 0;
  int64_t ma = INT_MAX;
  int x = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += abs(a[i]);
    ma = min(ma, abs(a[i]));
    if (a[i] < 0)
      ++x;
  }
  if (x % 2 == 0) {
    cout << sum << endl;
  } else {
    cout << sum - 2 * ma << endl;
  }

  return 0;
}
