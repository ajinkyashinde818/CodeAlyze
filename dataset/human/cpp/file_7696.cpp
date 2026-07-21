#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<long long> a(N);
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    sum += a[i];
  }
  long long ans = INT_MAX;
  for (int i = 0; i < N - 1; i++) {
    sum -= 2 * a[i];
    ans = min(ans, abs(sum));
  }
  cout << ans << endl;
  return 0;
}
