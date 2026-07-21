#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }

  long long ans = (1LL << 60);
  long long snuke = 0;
  long long kuma = sum;
  for (int i = 0; i < n - 1; i++) {
    snuke += a[i];
    kuma -= a[i];
    ans = min(ans, abs(snuke - kuma));
  }
  cout << ans << endl;

  return 0;
}
