#include <bits/stdc++.h>

using namespace std;

template <class T> inline bool chmin(T &a, T b) { /* {{{ */
  if (a > b) {
    a = b;
    return true;
  }
  return false;
} /* }}} */

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (i > 0) A[i] += A[i - 1];
  }
  long long ans = 1e15;
  for (int i = 0; i < N - 1; i++) {
    chmin(ans, abs(A[i] - (A[N - 1] - A[i])));
  }
  cout << ans << endl;

  return 0;
}
/* vim:set fdm=marker: */
