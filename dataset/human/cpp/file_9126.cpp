#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, M; cin >> N >> M;
  vector<string> A(N), B(M);
  for (int i = 0; i < N; ++i) cin >> A[i];
  for (int i = 0; i < M; ++i) cin >> B[i];

  for (int lx = 0; lx < N; ++lx) {
    for (int ly = 0; ly < N; ++ly) {
      if (lx+M > N or ly+M > N) continue;

      int is_matched = true;
      for (int x = 0; x < M; ++x) {
        for (int y = 0; y < M; ++y) {
          if (B[x][y] != A[lx+x][ly+y]) is_matched = false;
        }
      }

      if (is_matched) {
        cout << "Yes";
        return 0;
      }
    }
  }

  cout << "No";
}
