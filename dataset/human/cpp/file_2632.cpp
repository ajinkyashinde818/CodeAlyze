/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int64_t, int64_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N;
  cin >> N;
  vector<int64_t> A(N);
  // int64_t result = INT64_MIN;
  int64_t count_minus = 0;
  int64_t count_zero = 0;
  int64_t result = 0;
  for (int64_t i = 0; i < N; ++i) {
    int64_t a;
    cin >> a;
    if (a < 0) {
      ++count_minus;
    } else if (a == 0) {
      ++count_zero;
    }
    A[i] = abs(a);
    result += A[i];
  }
  if (count_zero > 0 || count_minus % 2 == 0) {
    cout << result << endl;
  } else {
    nth_element(A.begin(), A.begin(), A.end());
    result -= 2 * A[0];
    cout << result << endl;
  }

  return 0;
}
