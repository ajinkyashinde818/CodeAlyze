#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 123456;

long long N, C;
long long x[MAX_N], v[MAX_N], cw[MAX_N], ccw[MAX_N], max_query[MAX_N];

int main() {
  cin >> N >> C;
  for (int i = 0; i < N; ++i) cin >> x[i] >> v[i];
  long long res = 0;
  for (int i = 0; i < N; ++i) {
    cw[i] = v[i] - (i == 0 ? x[i] : (x[i] - x[i - 1]));
    if (i - 1 >= 0) cw[i] += cw[i - 1];
    res = max(res, cw[i]);
  }
  for (int i = N - 1; i >= 0; --i) {
    ccw[i] = v[i] - (i == N - 1 ? (C - x[i]) : (x[i + 1] - x[i]));
    if (i + 1 < N) ccw[i] += ccw[i + 1];
    res = max(res, ccw[i]);
  }

  for (int i = N - 1; i >= 0; --i) {
    max_query[i] = ccw[i];
    if (i + 1 < N) max_query[i] = max(max_query[i], max_query[i + 1]);
  } 
 
  for (int i = 0; i + 1 < N; ++i) {
    res = max(res, cw[i] - x[i] + max_query[i + 1]);
  }

  for (int i = 0; i < N; ++i) {
    max_query[i] = cw[i];
    if (i - 1 >= 0) max_query[i] = max(max_query[i], max_query[i - 1]);
  }
  for (int i = N - 1; i - 1 >= 0; --i) {
    res = max(res, ccw[i] - (C - x[i]) + max_query[i - 1]);
  }

  cout << res << endl;

  return 0;
}
