#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> A(N), B(M);
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < M; i++) cin >> B[i];

  for (int sy = 0; sy + M - 1 < N; sy++) {
    for (int sx = 0; sx + M - 1 < N; sx++) {
      bool is_same = true;
      for (int y = 0; y < M; y++) {
        int y2 = y + sy;
        for (int x = 0; x < M; x++) {
          int x2 = x + sx;
          if (A[y2][x2] != B[y][x]) {
            is_same = false;
            break;
          }
        }
      }

      if (is_same) {
        cout << "Yes\n";
        return 0;
      }
    }
  }

  cout << "No\n";

  return 0;
}
