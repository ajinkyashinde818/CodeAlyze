#include <iostream>
using namespace std;

using ll = long long;

int main() {
  // 入力
  int N;
  cin >> N;
  ll a[N];
  for (int i = 0; i < N; i++) cin >> a[i];

  ll sum = 0;
  for (int i = 1; i < N; i++) sum += a[i];

  ll tmp = a[0];
  ll ans = abs(tmp - sum);
  for (int i = 1; i < N - 1; i++) {
    tmp += a[i];
    sum -= a[i];
    ans = min(ans, abs(tmp - sum));
  }

  // 解答
  cout << ans << endl;

  return 0;
}
