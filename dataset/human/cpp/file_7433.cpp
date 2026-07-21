#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> sums(N);
  long long sum = 0;
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    sum += a;
    if (i == 0) {
      sums[i] = a;
    } else {
      sums[i] += sums[i - 1] + a;
    }
  }

  long long ans = 1e18;
  for (int i = 0; i < N - 1; ++i) {
    long long x = sums[i];
    long long y = sum - sums[i];
    ans = min(ans, abs(x - y));
  }
  cout << ans << endl;
  return 0;
}
