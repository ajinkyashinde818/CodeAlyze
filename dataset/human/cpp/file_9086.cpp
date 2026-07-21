#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> A(N), B(M);
  for (int i = 0; i < N; ++i) cin >> A[i];
  for (int i = 0; i < M; ++i) cin >> B[i];
  string ans = "No";
  for (int i1 = 0; i1 < N - M + 1; ++i1)
    for (int j1 = 0; j1 < N - M + 1; ++j1) {
      bool f = 1;
      for (int i2 = 0; i2 < M; ++i2)
        if (A[i1 + i2].substr(j1, M) != B[i2]) f = 0;
      if (f) ans = "Yes";
    }
  cout << ans << endl;
  return 0;
}
