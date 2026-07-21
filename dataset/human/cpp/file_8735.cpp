#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  string a[N];
  string b[M];

  for (int i = 0; i < N; i++) cin >> a[i];
  for (int i = 0; i < M; i++) cin >> b[i];

  for (int i = 0; i <= N - M; i++) {
    for (int j = 0; j <= N - M; j++) {
      // 判定
      bool isMatch = true;
      for (int x = 0; x < M; x++) {
        for (int y = 0; y < M; y++) {
          if (a[x + i][y + j] != b[x][y]) {
            isMatch = false;
            break;
          }
        }
        if (!isMatch) break;
      }

      if (isMatch) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
}
