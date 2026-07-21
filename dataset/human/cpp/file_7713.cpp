#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    long long r;
    cin >> r;
    a[i] = a[i - 1] + r;
  }
  long long ans = llabs(a[1] - a[0] - (a[n] - a[1]));
  for (int i = 1; i <= n - 1; i++) {
    long long x = a[i] - a[0], y = a[n] - a[i];
    long long tmp = llabs(x - y);
    if (tmp < ans) {
      ans = tmp;
    }
  }
  cout << ans << endl;
  return 0;
}
