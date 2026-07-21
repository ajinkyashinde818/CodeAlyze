#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using int64 = long long;

int64 Solve(const int64 N, const int64 C, const vector<int64>& x, const vector<int64>& v) {
  vector<int64> a(N);
  int64 sa = 0;
  for (int64 i = 0; i < N; ++i) {
    sa += v[i];
    a[i] = sa - x[i];
  }
  vector<int64> b(N);
  int64 sb = 0, mb = 0;
  for (int64 i = N - 1; i >= 0; --i) {
    sb += v[i];
    mb = max(mb, sb - (C - x[i]));
    b[i] = mb;
  }

  int64 ret = 0;
  for (int64 i = 0; i < N; ++i) {
    ret = max(ret, a[i]);  // no return
    if (i < N - 1)
      ret = max(ret, a[i] + b[i + 1] - x[i]);  // no return
  }
  return ret;
}

int main() {
  int64 N, C;
  cin >> N >> C;
  vector<int64> x(N), v(N);
  for (int64 i = 0; i < N; ++i) {
    cin >> x[i] >> v[i];
  }
  int64 a = Solve(N, C, x, v);
  for (int64 i = 0; i < N; ++i)
    x[i] = C - x[i];
  reverse(x.begin(), x.end());
  reverse(v.begin(), v.end());
  int64 b = Solve(N, C, x, v);
  cout << max(a, b) << "\n";
  return 0;
}
