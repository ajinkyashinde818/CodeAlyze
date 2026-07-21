#include <bits/stdc++.h>

using namespace std;
using i64 = std::int_fast64_t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<i64> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  i64 sum = 0, cnt = 0;
  for (int i = 0; i < N; i++) {
    sum += abs(A[i]);
    if (A[i] < 0) cnt++;
  }

  if (cnt % 2 != 0) {
    i64 minn = 1 << 28;
    for (int i = 0; i < N; i++) {
      minn = min(minn, abs(A[i]));
    }
    sum -= 2 * minn;
  }

  cout << sum << '\n';
  return 0;
}
