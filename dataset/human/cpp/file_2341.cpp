#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int64_t> a(n);
  for (auto&& e : a) cin >> e;
  int cnt(0);
  int64_t m(1000000000);
  int64_t ans(0);
  for (int i = 0; i < n; i++) {
    if (a[i] < 0) {
      ans -= a[i];
      cnt++;
      m = min(m, -1 * a[i]);
    } else {
      ans += a[i];
      m = min(m, a[i]);
    }
  }
  if (cnt % 2 != 0) {
    ans -= m * 2;
  }
  cout << ans << endl;
}
