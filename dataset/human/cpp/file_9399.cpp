#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> A(N), B(M);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < M; i++) {
    cin >> B[i];
  }
  bool ans = false;
  for (int i = 0; i < N - M + 1; i++) {
    for (int j = 0; j < N - M + 1; j++) {
      bool ok = true;
      for (int x = 0; x < M; x++) {
        for (int y = 0; y < M; y++) {
          if (A[i + x][j + y] != B[x][y]) {
            ok = false;
            break;
          }
        }
      }
      if (ok) {
        ans = true;
        break;
      }
    }
  }
  if (ans) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
/* vim:set fdm=marker: */
